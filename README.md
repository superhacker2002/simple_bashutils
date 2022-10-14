# Simple Bash Utils

Development of Bash text utilities: cat, grep.

## Contents

1. [Introduction](#introduction)
2. [Information](#information) \
   2.1. [s21_cat Usage](#working-with-the-cat-utility) \
   2.2. [s21_grep Usage](#working-with-grep-utility)  

## Introduction

In this project I have learned and developed Bash utilities for working with C programming language texts. These utilities (cat and grep) are often used in the Linux terminal.

## Information

### s21_cat Usage

s21_cat has similar options and usage to original Linux utility cat.

Cat is one of the most frequently used commands on Unix-like operating systems. It has three related functions with regard to text files: displaying them, combining copies of them and creating new ones.

In order to use utility compile it with the makefile goal s21_cat, then use it according to the pattern:

`./s21_cat [OPTION] [FILE]...`

### s21_cat Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

### s21_grep Usage

s21_grep has similar options and usage to original Linux utility grep.

In order to use utility compile it with the makefile goal s21_grep, then use it according to the pattern:

`./s21_grep [options] template [file_name]`

### s21_grep Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase.  |
| 3 | -v | Invert match. |
| 4 | -c | Output count of matching lines only. |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. |
| 7 | -h | Output matching lines without preceding them by file names. |
| 8 | -s | Suppress error messages about nonexistent or unreadable files. |
| 9 | -f file | Take regexes from a file. |
| 10 | -o | Output the matched parts of a matching line. |
