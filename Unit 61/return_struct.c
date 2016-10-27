#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

struct Person {
    char name[20];
    int age;
    char address[100];
};

struct Person getPerson()    // Person ����ü�� ��ȯ�ϴ� getPerson �Լ� ����
{
    struct Person p;

    strcpy(p.name, "ȫ�浿");
    p.age = 30;
    strcpy(p.address, "����� ��걸 �ѳ���");

    return p;    // ����ü ���� ��ȯ
}

int main()
{
    struct Person p1;

    p1 = getPerson();    // ��ȯ�� ����ü ������ ������ p1�� ��� �����

    // getPerson���� ������ ���� ��µ�
    printf("�̸�: %s\n", p1.name);       // ȫ�浿
    printf("����: %d\n", p1.age);        // 30
    printf("�ּ�: %s\n", p1.address);    // ����� ��걸 �ѳ���

    return 0;
}
