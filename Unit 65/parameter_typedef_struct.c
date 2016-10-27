#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

typedef struct _Person {
    char name[20];
    int age;
    char address[100];
} Person, *PPerson;    // ����ü ��Ī Person, ����ü ������ ��Ī PPerson

void setPerson(PPerson p)    // Person ����ü �������� ��Ī�� �Ű������� ����
{
    strcpy(p->name, "��浿");
    p->age = 40;
    strcpy(p->address, "����� ���ʱ� ������");
}

int main()
{
    Person p1;

    strcpy(p1.name, "ȫ�浿");
    p1.age = 30;
    strcpy(p1.address, "����� ��걸 �ѳ���");

    setPerson(&p1);    // �Լ��� ȣ���� �� ����ü ������ �޸� �ּҸ� ����

    // setPerson���� ������ ���� ��µ�
    printf("�̸�: %s\n", p1.name);       // �̸�: ��浿
    printf("����: %d\n", p1.age);        // ����: 40
    printf("�ּ�: %s\n", p1.address);    // �ּ�: ����� ���ʱ� ������

    return 0;
}
