#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    char c1;

    scanf("%c", &c1);    // ���� �Է¹���

    switch (c1)  // c1�� ���� ���� �б�
    {
    case 'a':    // ���� a�� ��
        printf("a�Դϴ�.\n");
        break;
    case 'b':    // ���� b�� ��
        printf("b�Դϴ�.\n");
        break;
    default:    // �ƹ� case���� �ش���� ���� ��
        printf("default\n");
        break;
    }

    return 0;
}
