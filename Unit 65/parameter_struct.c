#define _CRT_SECURE_NO_WARNINGS   // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

struct Person {
    char name[20];
    int age;
    char address[100];
};

void printPerson(struct Person p)    // ��ȯ�� ����, ����ü �Ű����� �� �� ����
{
    // ����ü �Ű����� ����� �� ���
    printf("�̸�: %s\n", p.name);       // �̸�: ȫ�浿
    printf("����: %d\n", p.age);        // ����: 30
    printf("�ּ�: %s\n", p.address);    // �ּ�: ����� ��걸 �ѳ���
}

int main()
{
    struct Person p1;

    strcpy(p1.name, "ȫ�浿");
    p1.age = 30;
    strcpy(p1.address, "����� ��걸 �ѳ���");

    printPerson(p1);    // �Լ��� ȣ���� �� ����ü ���� ����, ����� �����

    return 0;
}
