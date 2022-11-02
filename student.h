#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define FIO_COUNT 16

static const int N = 64;

struct student
{
    char fio[FIO_COUNT];
    int stipa;
};

void display_students(struct student*, int);
void input_students_info(struct student*, int);

void input_fio(char*);
void input_stipa(char*);

int check_str(char*);

#endif // STUDENT_H
