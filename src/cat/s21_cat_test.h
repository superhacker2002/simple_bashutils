#ifndef SRC_CAT_S21_CAT_TEST_H_
#define SRC_CAT_S21_CAT_TEST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

void start_general_tests();
void start_gnu_tests();
void file_gen();
int compare();

static const char *const s21_mac_flags[6] = {
    " -b ",
    " -e ",
    " -v ",
    " -n ",
    " -s ",
    " -t "
};

static const char *const s21_GNU_flags[5] = {
    " --number-nonblank ",
    " -E ",
    " --number ",
    " --squeeze-blank ",
    " -T "
};

#endif  //  SRC_CAT_S21_CAT_TEST_H_
