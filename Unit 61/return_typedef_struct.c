#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

typedef struct _Person {
    char name[20];
    int age;
    char address[100];
} Person, *PPerson;    // ����ü ��Ī Person, ����ü ������ ��Ī PPerson

PPerson allocPerson()    // Person ����ü �������� ��Ī�� ��ȯ�� �ڷ������� ����
{
    PPerson p = malloc(sizeof(Person));    // ����ü �����Ϳ� ���� �޸� �Ҵ�

    strcpy(p->name, "ȫ�浿");
    p->age = 30;
    strcpy(p->address, "����� ��걸 �ѳ���");

    return p;    // ����ü ������ ��ȯ
}

int main()
{
    PPerson p1;

    p1 = allocPerson();    // �����͸� ��ȯ�Ͽ� p1�� �޸� �ּ� ����

    // allocPerson���� ������ ������ ��µ�
    printf("�̸�: %s\n", p1->name);       // �̸�: ȫ�浿
    printf("����: %d\n", p1->age);        // ����: 30
    printf("�ּ�: %s\n", p1->address);    // �ּ�: ����� ��걸 �ѳ���

    free(p1);    // ���� �޸� ����

    return 0;
}
