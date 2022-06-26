#include "s21_cat.h"

int main(int argc, char *argv[]) {
    int error_flag = 0;
    while (!error_flag) {
        int option = 0;
        option = getopt_long(argc, argv, optstring, longopts, NULL);  // get option symbol
        if (option == -1) break;  // no more options
        error_flag = get_flags(option);  // option is (not) in optstring
    }
    if (error_flag) {  // non-valid option
        printf("usage: %s [-benstv --number-nonblank --number --squeeze-blank] [file ...]\n", argv[0]);
    } else {
        argc -= optind, argv += optind;  // go to filename
        FILE *file_to_open = NULL;
        while (*argv != NULL) {
            if ((file_to_open = fopen(*argv, "r")) != NULL) {
                s21_cat(file_to_open);
                fclose(file_to_open);
            } else {
                printf("s21cat: %s: No such file or directory", *argv);
                break;
            }
            argv++;
        }
    }
}

int get_flags(char option) {
    int error_flag = 0;
    switch (option) {
        case 'b':
            b_option_found = n_option_found = 1;
            break;
        case 'n':
            n_option_found = 1;
            break;
        case 's':
            s_option_found = 1;
            break;
        case 'E':
            e_option_found = 1;
            break;
        case 'v':
            v_option_found = 1;
            break;
        case 'e':
            e_option_found = v_option_found = 1;
            break;
        case 'T':
            t_option_found = 1;
            break;
        case 't':
            t_option_found = v_option_found = 1;
            break;
        default:
            error_flag = 1;
    }
    return error_flag;
}

void s21_cat(FILE *file) {
    int symbol, prev;
    long unsigned line_counter = 0;
    for (prev = '\n'; (symbol = getc(file)) != EOF; prev = symbol) {
        if (prev == '\n') {  //
            if (s_option_found) {  // duplicate empty lines deletion
                if (symbol == '\n') {
                    if (empty_line_found) continue;
                    empty_line_found = 1;
                } else {
                    empty_line_found = 0;
                }
            }
            if (n_option_found) {  // all lines numeration
                if (!b_option_found || symbol != '\n') printf("%6lu\t", ++line_counter);
                // non-empty lines numeration
            }
        }
        if (symbol == '\n') {  // reached the line end
            if (e_option_found)  printf("%c", '$');  // dollar sign at line end
        } else if (symbol == '\t') {
            if (t_option_found) {  // tabulation as ^T
                printf("^I");
                continue;
            }
        } else if (v_option_found) {  // display non-printed symbols
            if (!isascii(symbol)) {
                printf("M-");
                symbol = toascii(symbol);
            }
            if (iscntrl(symbol)) {
                printf("^%c", symbol == '\177' ? '?' : symbol | 0100);
                continue;
            }
        }
        printf("%c", symbol);
    }
}
