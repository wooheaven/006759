#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int num1;

    scanf("%d", &num1);    // ���� �Է¹���

    // switch�� case���� break ����
    switch (num1)
    {
    case 1:    // 1�� ���� �Ʒ� case 2, default�� ��� �����
        printf("1�Դϴ�.\n");
    case 2:    // 2�� ���� �Ʒ� default���� �����
        printf("2�Դϴ�.\n");
    default:
        printf("default\n");
    }

    return 0;
}
