#include <stdio.h>

struct Person {    // ����ü ����
    char name[20];        // ����ü ��� 1
    int age;              // ����ü ��� 2
    char address[100];    // ����ü ��� 3
};

int main()
{
    struct Person p1;      // ����ü ���� ����
    struct Person *ptr;    // ����ü ������ ����

    ptr = &p1;    // p1�� �޸� �ּҸ� ���Ͽ� ptr�� �Ҵ�

    // ȭ��ǥ �����ڷ� ����ü ����� �����Ͽ� �� �Ҵ�
    ptr->age = 30;

    printf("����: %d\n", p1.age);      // ����: 30: ����ü ������ ��� �� ���
    printf("����: %d\n", ptr->age);    // ����: 30: ����ü �������� ��� �� ���

    return 0;
}
