#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "file.cpp"
#include "student.cpp"

int cmp_by_second_name(const void*, const void*);

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

    index = input_students_info(students, 0);
    display_students(students, index);

    qsort(students, index, sizeof(struct student), cmp_by_second_name);
    display_students(students, index);

    write2file("students.bin", students, index);
    readfile("students.bin", out_students, index);

    display_students(out_students, index);

    if(index < N)
    {
        index = input_students_info(out_students, index);

        qsort(students, index, sizeof(struct student), cmp_by_second_name);
        display_students(out_students, index);

        write2file("out-students.bin", out_students, index);
    }

    printf("The program has been successfully completed!");

    return 0;
}

int cmp_by_second_name(const void* firstname, const void* secondname)
{
    return strcmp(((struct student*)firstname)->fio, ((struct student*)secondname)->fio);
}
