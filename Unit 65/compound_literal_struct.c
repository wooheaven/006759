#include <stdio.h>

struct Person {
    char name[20];
    int age;
    char address[100];
};

void printPerson(struct Person p)
{
    printf("�̸�: %s\n", p.name);
    printf("����: %d\n", p.age);
    printf("�ּ�: %s\n", p.address);
}

int main()
{
    // ���� ���ͷ� ������� ����ü�� �Ѱ���
    printPerson((struct Person) { .name = "ȫ�浿", .age = 30, .address = "����� ��걸 �ѳ���" });

    // ���� ���ͷ� ������� ����ü�� �Ѱ���. ��� �̸� ����
    printPerson((struct Person) { "��浿", 40, "����� ���ʱ� ������" });

    return 0;
}
