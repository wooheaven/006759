#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
    char address[100];
};

typedef struct {
    char name[20];
    int number;
    int displacement;
} Car;

int main()
{
    /*________________________________________________








    ________________________________________________*/

    printf("�̸�: %s\n", p1->name);
    printf("����: %d\n", p1->age);
    printf("�ּ�: %s\n", p1->address);

    printf("�ڵ��� �̸�: %s\n", c1->name);
    printf("�ڵ��� ��ȣ: %d\n", c1->number);
    printf("��ⷮ: %dcc\n", c1->displacement);

    free(p1);
    free(c1);

    return 0;
}
