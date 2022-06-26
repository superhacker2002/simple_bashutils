#include "s21_grep.h"

int s21_grep(int argc, char *argv[]) {
    int patterns_counter = count_patterns(argc, argv);
    // printf("pre patterns_countr %d\n", patterns_counter);
    regex_t *all_patterns = calloc(patterns_counter, sizeof(regex_t));  // массив шаблонов

    finded_options options_struct;  // массив флагов
    memset(&options_struct, '0', sizeof(finded_options));
    int files_counter = 0;
    patterns_counter = argv_parsing(&options_struct, argc, argv, all_patterns, &files_counter);

    find_all_matching(&options_struct, all_patterns, argv, argc, patterns_counter, files_counter);
    cleaning(all_patterns, patterns_counter);
    free(all_patterns);
    return 0;
}

int argv_parsing(finded_options *options_struct, int argc, char **argv,
                            regex_t *all_patterns, int *files_counter) {
    int option_index = 1, is_pattern = 0, pattern_index = 0;
    while (argv[option_index]) {
        options_struct->e_opt = '0';
        options_struct->f_opt = '0';
        if (strlen(argv[option_index]) == 2 && argv[option_index][0] == '-') {
            is_pattern = get_options(argv[option_index][1], options_struct);
            if (is_pattern && options_struct->e_opt == '1') {
                all_patterns[pattern_index++] = get_pattern(argv[option_index + 1], options_struct);
                option_index++;
            } else if (is_pattern && options_struct->f_opt == '1') {
                get_patterns_from_file(argv[option_index + 1], all_patterns, &pattern_index, options_struct);
                option_index++;
            }
        } else {
            if (is_pattern == 0) {
                all_patterns[pattern_index++] = get_pattern(argv[option_index++], options_struct);
            }
            break;
        }
        option_index++;
    }
    *files_counter = argc - (option_index);
    return pattern_index;
}


void find_all_matching(finded_options *opts, regex_t *all_patterns, char **argv,
                                int argc, int patterns_counter, int files_counter) {
    int value = 0;
    FILE *file_to_read = NULL;
    char file_buffer[1000];
    memset(file_buffer, '\0', 1000);
    regmatch_t pmatch;
    int epmty_last_line = 0;
    for (int i = argc - files_counter; i < argc; i++) {
        file_to_read = fopen(argv[i], "r");
        if (file_to_read) {
            int matching_counter = 0, lines_counter = 0;
            while (!feof(file_to_read)) {
                fgets(file_buffer, 1000, file_to_read);
                lines_counter++;
                if (file_buffer[0] == EOF)  {
                    epmty_last_line = 1;
                    break;
                }
                for (int j = 0; j < patterns_counter; j++) {
                    int offset = 0;
                    if (opts->l_opt != '1' && opts->o_opt == '1') {
                        while (offset < (int)strlen(file_buffer)) {
                            value = regexec(&all_patterns[j], file_buffer + offset, 1, &pmatch, 0);
                            if (value == 0 && files_counter > 1) printf("%s:", argv[i]);
                            print_o_lines(file_buffer, value, &pmatch, &offset);
                        }
                    } else {
                        value = regexec(&all_patterns[j], file_buffer, 1, &pmatch, 0);
                    }
                    matching_counter += print_lines(value, file_buffer, opts, files_counter,
                                                                    argv[i], lines_counter);
                }
                file_buffer[0] = EOF;
            }
            if (!epmty_last_line && opts->v_opt == '1') printf("\n");
            if (opts->c_opt == '1' && files_counter > 1) printf("%s:%d\n", argv[i], matching_counter);
            else if (opts->c_opt == '1' && files_counter == 1) printf("%d\n", matching_counter);
            if (opts->l_opt == '1' && matching_counter > 0) printf("%s\n", argv[i]);
            fclose(file_to_read);
        } else if (opts->s_opt == '0') {
            printf("s21_grep: %s: No such file or directory", argv[i]);
        }
    }
}

void print_o_lines(char *file_buffer, int value, regmatch_t *pmatch, int *offset) {
    if (value == 0 && pmatch->rm_so != -1) {
        for (char *c = (file_buffer + pmatch->rm_so); c < file_buffer + pmatch->rm_eo; c++) {
            printf("%c", *c);
        }
        printf("\n");
    }
    *offset += pmatch->rm_eo;
}

int print_lines(int value, char *file_buffer, finded_options *options, int files_counter,
                                                        char *file_path, int lines_counter) {
    int compiling_result = 0, matching_counter = 0;
    if (options->v_opt == '1') compiling_result = REG_NOMATCH;
    if (value == compiling_result) matching_counter++;

    if (options->c_opt == '0' && options->l_opt == '0' && options->n_opt == '0') {
        if (value == compiling_result && files_counter > 1 && options->h_opt == '0') {
            printf("%s:%s", file_path, file_buffer);
        } else if (value == compiling_result && (files_counter == 1 || options->h_opt == '1')) {
            printf("%s", file_buffer);
        }

    } else if (options->n_opt == '1') {
        if (value == compiling_result && files_counter > 1 && options->h_opt == '0') {
            printf("%s:%d:%s", file_path, lines_counter, file_buffer);
        } else if (value == compiling_result && (files_counter == 1 || options->h_opt == '1')) {
            printf("%d:%s", lines_counter, file_buffer);
        }
    }
    return matching_counter;
}

void cleaning(regex_t *all_patterns, int patterns_counter) {
    for (int i = 0; i < patterns_counter; i++) {
        regfree(all_patterns++);
    }
}

int get_options(int option, finded_options *options) {
    int is_pattern = 0;
    if (option == 'i') {
        options->i_opt = '1';
    } else if (option == 'v') {
        options->v_opt = '1';
    } else if (option == 'c') {
        options->c_opt = '1';
    } else if (option == 'l') {
        options->l_opt = '1';
    } else if (option == 'n') {
        options->n_opt = '1';
    } else if (option == 'o') {
        options->o_opt = '1';
    } else if (option == 'h') {
        options->h_opt = '1';
    } else if (option == 's') {
        options->s_opt = '1';
    } else if (option == 'e' || option == 'f') {
        is_pattern = 1;
        if (option == 'e') {
            options->e_opt = '1';
        } else if (option == 'f') {
            options->f_opt = '1';
        }
    }
    return is_pattern;
}

int count_patterns(int argc, char **argv) {
    int patterns_counter = 0;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && (argv[i][1] == 'f' || argv[i][1] == 'e')) {
            patterns_counter++;
        }
    }
    return patterns_counter ? patterns_counter : 1;
}

regex_t get_pattern(char *argv, finded_options *options) {
    regex_t pattern;
    int comp_flag = cflag_def;
    if (options->i_opt == '1') comp_flag = cflag_i;
    regcomp(&pattern, argv, comp_flag);
    return pattern;
}

void get_patterns_from_file(char *file_path, regex_t *all_patterns,
                            int *pattern_index, finded_options *options) {
    FILE *pattern_file = fopen(file_path, "r");
    if (pattern_file) {
        char pattern_from_file[1000];
        int patterns_in_file = 0;
        while (!feof(pattern_file)) {
            memset(pattern_from_file, '\0', 1000);
            fgets(pattern_from_file, 1000, pattern_file);
            patterns_in_file++;
            all_patterns[*pattern_index] = get_pattern(pattern_from_file, options);
            *pattern_index = *pattern_index + 1;
            if (!feof(pattern_file)) {
                all_patterns = realloc(all_patterns, (*pattern_index + patterns_in_file) * sizeof(regex_t));
            }
        }
        fclose(pattern_file);
    }
}
