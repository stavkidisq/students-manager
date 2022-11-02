#include "student.h"

void display_students(struct student* students, int index)
{
    printf("Our students:\n");

    for(int i = 0; i < index; i++)
        printf("Student %d: %s, %d\n", i, students[i].fio, students[i].stipa);
}

int input_students_info(struct student* students, int start_index)
{
    char stipa[10];

    while(start_index < N)
    {
        input_fio(students[start_index].fio);

        if(strcmp(students[start_index].fio, "") == 0)
            break;

        do
        {
            input_stipa(stipa);
        }
        while(check_str(stipa) == 0); // Стипендия должна состоять только из цифр.

        students[start_index].stipa = atoi(stipa);
        start_index++;
    }

    return start_index;
}

void input_fio(char* fio)
{
    printf("Enter second name: ");
    gets(fio);
}

void input_stipa(char* stipa)
{
    printf("Enter scholarship amount: ");
    gets(stipa);
}

int check_str(char* str)
{
    while(*str)
    {
        if(isdigit(*str) == 0)
            return 0;

        ++str;
    }

    return 1;
}
