#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int grade;
    int class;
    float average;
};

int main()
{
    struct Student *s1 = /*(1)_______________________*/;

    /*(2)_______________________
    ____________________________
    ____________________________
    __________________________*/

    printf("�̸�: %s\n", s1->name);
    printf("�г�: %d\n", s1->grade);
    printf("��: %d\n", s1->class);
    printf("�������: %f\n", s1->average);

    free(s1);

    return 0;
}
