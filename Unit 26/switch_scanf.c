#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int num1;

    scanf("%d", &num1);    // ���� �Է¹���

    switch (num1)   // num1�� ���� ���� �б�
    {
    case 1:         // 1�� ��
        printf("1�Դϴ�.\n");
        break;
    case 2:         // 2�� ��
        printf("2�Դϴ�.\n");
        break;
    default:        // �ƹ� case���� �ش���� ���� ��
        printf("default\n");
        break;
    }

    return 0;
}
