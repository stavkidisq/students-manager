#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.h"
#include "student.h"

int cmp_by_second_name(struct student, struct student);
void bubble_sort(struct student*, int);
int get_start_index(struct student*);

/*
    Имя программы: students-manager.
    Назначение программы: запись/чтение в файл информации о студентах.
    Автор: Рабцевич Александр.
    Дата создания: 31.10.22.
*/

int main()
{
    struct student students[N];
    struct student out_students[N];
    int index;

    input_students_info(students, 0);
    index = get_start_index(students);

    if(index > 0)
    {
        printf("Students list before sorting.\n");
        display_students(students, index);

        bubble_sort(students, index);

        printf("Students list after sorting.\n");
        display_students(students, index);

        write2file("students.bin", students, index);
        readfile("students.bin", out_students, index);

        printf("Output students list.\n");
        display_students(out_students, index);
    }
    else
    {
        printf("Students list is empty!\n");
    }

    if(index < N)
    {
        input_students_info(out_students, index);
        index = get_start_index(out_students);

        if(index > 0)
        {
            bubble_sort(out_students, index);

            printf("Output students list after sorting.\n");
            display_students(out_students, index);
        }
        else
        {
            printf("Students list is empty!\n");
        }

        write2file("out-students.bin", out_students, index);
    }
    else
    {
        printf("Students list is full!");
    }

    printf("The program has been successfully completed!");

    return 0;
}

int get_start_index(struct student* students)
{
    for(int i = 0; i < N; i++)
    {
        if(strcmp(students[i].fio, "") == 0)
            return i;
    }

    return N;
}

int cmp_by_second_name(struct student first_student, struct student second_student)
{
    return strcmp(first_student.fio, second_student.fio);
}

void bubble_sort(struct student* students, int index)
{
    struct student temp;
    for(int i = 0; i < index - 1; i++)
    {
        for(int j = index - 1; j > i; j--)
        {
            if(cmp_by_second_name(students[j - 1], students[j]) > 0)
            {
                temp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = temp;
            }
        }
    }
}
