#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.h"
#include "student.h"

int cmp_by_second_name(struct student, struct student);
void bubble_sort(struct student*, int);

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
    int index = 0;

    index = input_students_info(students, 0);
    display_students(students, index);

    bubble_sort(students, index);
    display_students(students, index);

    write2file("students.bin", students, index);
    readfile("students.bin", out_students, index);

    display_students(out_students, index);

    if(index < N)
    {
        index = input_students_info(out_students, index);

        bubble_sort(out_students, index);
        display_students(out_students, index);

        write2file("out-students.bin", out_students, index);
    }

    printf("The program has been successfully completed!");

    return 0;
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
