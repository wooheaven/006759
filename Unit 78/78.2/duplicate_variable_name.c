#include <stdio.h>

int num1 = 10;    // ���� ������ �̸��� num1

int main()
{
    int num1 = 20;    // ���� ������ �̸��� num1

    {
        int num1 = 30;           // ��� �ȿ� ����� ���� ������ �̸��� num1
        printf("%d\n", num1);    // 30: ���� ����� ������ ���
    }

    printf("%d\n", num1);    // 20: ���� ����� ������ ���

    return 0;
}
