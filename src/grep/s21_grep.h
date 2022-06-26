#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define s21_grep main
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#define grep_options "efivclnhso"
#define filename_len 260

#if defined (__APPLE__)
    #define cflag_def REG_BASIC
#elif defined (__linux__)
    #define cflag_def 0
#endif
#define cflag_i REG_ICASE

typedef struct {
    char i_opt;
    char v_opt;
    char c_opt;
    char l_opt;
    char n_opt;
    char h_opt;
    char s_opt;
    char o_opt;
    char f_opt;
    char e_opt;
} finded_options;

int argv_parsing(finded_options *options_struct, int argc, char **argv,
                            regex_t *all_patterns, int *files_counter);
int get_options(int option, finded_options *options);
regex_t get_pattern(char *argv, finded_options *options);
void get_patterns_from_file(char *file_path, regex_t *all_patterns,
                            int *pattern_index, finded_options *options);
int count_patterns(int argc, char **argv);
regex_t get_all_patterns(int patterns_counter);
void find_all_matching(finded_options *opts, regex_t *all_patterns, char **argv,
                                int argc, int patterns_counter, int files_counter);
void cleaning(regex_t *all_patterns, int patterns_counter);
int print_lines(int value, char *file_buffer, finded_options *options,
                    int files_counter, char *file_path, int lines_counter);
void print_o_lines(char *file_buffer, int value, regmatch_t *pmatch, int *offset);

#endif  // SRC_GREP_S21_GREP_H_


