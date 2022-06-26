#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <ctype.h>

int b_option_found = 0, n_option_found = 0, v_option_found = 0;
int t_option_found = 0, e_option_found = 0, s_option_found = 0;
int empty_line_found = 0;

const struct option longopts[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {0, 0, 0, 0}
};

const char *optstring = "beEnstTv";

int get_flags(char option);
void s21_cat(FILE *file);

#endif  // SRC_CAT_S21_CAT_H_
