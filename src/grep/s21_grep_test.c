#include "s21_grep_test.h"
int main(void) {
    test_e();
    test_i();
    test_noflags();
    test_v();
    test_c();
    test_l();
    test_n();
    test_h();
    test_s();
    test_f();
    test_o();
    tests_1();
    tests_2();
    tests_3();
    tests_4();
    tests_5();
    tests_6();
    tests_7();
    tests_8();
    tests_9();
    tests_10();
    tests_11();
    tests_12();
    tests_13();
    testy_1();
    testy_2();
    testy_3();
    testy_5();
    testy_6();
    testy_7();
    testy_8();
    testy_9();
    testy_10();
    testy_11();
    testy_12();
    testy_13();
    return 0;
}
void test_e() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -e people tmp1 > v1");
    strcat(command2, "./s21_grep -e people tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -e people -e variant tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -e people -e variant tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -e people -e variant -e press tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -e people -e variant -e press tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_noflags() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep coronavirus tmp1 > v1");
    strcat(command2, "./s21_grep coronavirus tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep coronavirus tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep coronavirus tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_i() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -i Coronavirus tmp1 > v1");
    strcat(command2, "./s21_grep -i Coronavirus tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -i Coronavirus tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -i Coronavirus tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_v() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -v Coronavirus tmp1 > v1");
    strcat(command2, "./s21_grep -v Coronavirus tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -v Coronavirus tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -v Coronavirus tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_c() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -c health tmp1 > v1");
    strcat(command2, "./s21_grep -c health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -c health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -c health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_l() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -l health tmp1 > v1");
    strcat(command2, "./s21_grep -l health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -l health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -l health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_n() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -n health tmp1 > v1");
    strcat(command2, "./s21_grep -n health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -n health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -n health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_h() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -h health tmp1 > v1");
    strcat(command2, "./s21_grep -h health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -h health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -h health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_s() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -s health tmp1 > v1");
    strcat(command2, "./s21_grep -s health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -s health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -s health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_f() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -f all tmp1 > v1");
    strcat(command2, "./s21_grep -f all tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -f all tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -f all tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void test_o() {
    char command1[512];
    char command2[512];
    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -o health tmp1 > v1");
    strcat(command2, "./s21_grep -o health tmp1 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);

    memset(command1, '\0', 512);
    memset(command2, '\0', 512);
    strcat(command1, "grep -o health tmp1 tmp2 > v1");
    strcat(command2, "./s21_grep -o health tmp1 tmp2 > v2");
    printf("%s\n%s\n", command1, command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i  -n coronavirus tmp1 > v1");
    strcat(command2, " -i  -n coronavirus tmp1  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -v -f all tmp1 > v1");
    strcat(command2, " -v -f all tmp1 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void tests_3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -c tudor tmp2 > v1");
    strcat(command2, " -i -c tudor tmp2  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_4() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -v British tmp2 > v1");
    strcat(command2, " -i -v British tmp2  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_5() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -h against tmp2 > v1");
    strcat(command2, " -i -h against tmp2  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_6() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -o opinion  tmp2 > v1");
    strcat(command2, " -i -o opinion  tmp2  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_7() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -n foxe  tmp2 > v1");
    strcat(command2, " -i -n foxe  tmp2  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void testy_1() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -e Paris tmp3 > v1");
    strcat(command2, " -e Paris tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void testy_2() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h -e writer  tmp3 > v1");
    strcat(command2, " -h -e writer  tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void testy_3() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h -f all tmp3 > v1");
    strcat(command2, " -h -f all tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}


void testy_5() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h -v black tmp3 > v1");
    strcat(command2, " -h -v black tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_6() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -l -o bodies tmp3 > v1");
    strcat(command2, " -l -o bodies tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_7() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h -c white tmp3 > v1");
    strcat(command2, " -h -c white tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_8() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -h -i city tmp3 > v1");
    strcat(command2, " -h -i city tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_9() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -n -s skin tmp3 > v1");
    strcat(command2, " -n -s skin tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_10() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -l -s cemetery tmp3 > v1");
    strcat(command2, " -l -s cemetery tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void testy_11() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -i -s bones tmp3 > v1");
    strcat(command2, " -i -s bones tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void testy_12() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -c -e ^public tmp3 > v1");
    strcat(command2, " -c -e ^public tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void testy_13() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -n -v through tmp3 > v1");
    strcat(command2, " -n -v through tmp3 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_8() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -ve health  tmp4 > v1");
    strcat(command2, " -ve health  tmp4  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void tests_9() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -in coronavirus  tmp1 > v1");
    strcat(command2, " -in coronavirus  tmp1  > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void tests_10() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -iv coronavirus  tmp1 tmp2 > v1");
    strcat(command2, " -iv coronavirus  tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
void tests_11() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -cv coronavirus  tmp1 tmp2 > v1");
    strcat(command2, " -cv coronavirus  tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_12() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -lv coronavirus  tmp1 tmp2 > v1");
    strcat(command2, " -lv coronavirus  tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}

void tests_13() {
    char command1[512] = {'\0'};
    char command2[512] = {'\0'};
    strcat(command1, "grep");
    strcat(command2, "./s21_grep");
    strcat(command1, " -ho coronavirus  tmp1 tmp2 > v1");
    strcat(command2, " -ho coronavirus  tmp1 tmp2 > v2");
    printf("%s\n", command1);
    printf("%s\n", command2);
    system(command1);
    system(command2);
    system("diff v1 v2") ? printf("%sFAIL%s\n", RED, RESET) : printf("%sOK!%s\n", GRN, RESET);
}
