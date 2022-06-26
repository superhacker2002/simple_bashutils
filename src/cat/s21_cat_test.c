#include "s21_cat_test.h"

int main(void) {
    start_general_tests();
    #if defined (__linux__)
    start_gnu_tests();
    #endif
    return 0;
}

void start_general_tests() {
    int len = 64;
    char buff[len + 1][32];
    for (int i = 0; i < len; i++) {
        memset(buff[i], '\0', 32);
        if (i & 0b000001) strcat(buff[i], s21_mac_flags[0]);
        if (i & 0b000010) strcat(buff[i], s21_mac_flags[1]);
        if (i & 0b000100) strcat(buff[i], s21_mac_flags[2]);
        if (i & 0b001000) strcat(buff[i], s21_mac_flags[3]);
        if (i & 0b010000) strcat(buff[i], s21_mac_flags[4]);
        if (i & 0b100000) strcat(buff[i], s21_mac_flags[5]);
    }
    for (int i = 0; i < len; i++) {
        file_gen();
        char command1[512];
        char command2[512];
        memset(command1, '\0', 512);
        memset(command2, '\0', 512);
        strcat(command1, "cat");
        strcat(command2, "./s21_cat");
        strcat(command1, buff[i]);
        strcat(command2, buff[i]);
        strcat(command1, " tmp_test_file1 > tmp1");
        strcat(command2, " tmp_test_file2 > tmp2");
        printf("%s\n%s\n", command1, command2);
        system(command1);
        system(command2);
        system("diff tmp1 tmp2") ? printf("%sFAIL%s\n", RED, RESET) :
        printf("%sOK!%s\n", GRN, RESET);
    }
}

void start_gnu_tests() {
    int len = 32;
    char buff[len + 1][32];
    for (int i = 0; i < len; i++) {
        memset(buff[i], '\0', 32);
        if (i & 0b000001) strcat(buff[i], s21_GNU_flags[0]);
        if (i & 0b000010) strcat(buff[i], s21_GNU_flags[1]);
        if (i & 0b000100) strcat(buff[i], s21_GNU_flags[2]);
        if (i & 0b001000) strcat(buff[i], s21_GNU_flags[3]);
        if (i & 0b010000) strcat(buff[i], s21_GNU_flags[4]);
    }
    for (int i = 0; i < len; i++) {
        file_gen();
        char command1[512];
        char command2[512];
        memset(command1, '\0', 512);
        memset(command2, '\0', 512);
        strcat(command1, "cat");
        strcat(command2, "./s21_cat");
        strcat(command1, buff[i]);
        strcat(command2, buff[i]);
        strcat(command1, " tmp_test_file1 > tmp1");
        strcat(command2, " tmp_test_file2 > tmp2");
        printf("%s\n%s\n", command1, command2);
        system(command1);
        system(command2);
        system("diff tmp1 tmp2") ? printf("%sFAIL%s\n", RED, RESET) :
        printf("%sOK!%s\n", GRN, RESET);
    }
}

void file_gen(void) {
    int len = rand() % 10000;
    FILE *fd1 = fopen("tmp_test_file1", "w");
    FILE *fd2 = fopen("tmp_test_file2", "w");
    if (fd1 && fd2) {
        for (int i = 0; i < len; i++) {
            unsigned char c = rand() % 127;
            fputc(c, fd1);
            fputc(c, fd2);
        }
        fclose(fd1);
        fclose(fd2);
    } else {
        perror("");
    }
}
