#include <stdio.h>

int num1 = 10;    // ���� ���� ���� �� �� �ʱ�ȭ

void printGlobal()
{
    printf("%d\n", num1);    // 20: main �Լ����� ������ ���� ��� ������
}

int main()
{
    printf("%d\n", num1);    // 10: main �Լ����� ���� ���� num1�� �� ���

    num1 = 20;    // ���� ���� num1�� 20 ����

    printGlobal();    // 20: printGlobal �Լ����� ���� ���� num1�� �� ���

    return 0;
}
