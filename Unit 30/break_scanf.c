#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    int i = 1;
    while (1)              // ���� ����
    {
        printf("%d\n", i);
        if (i == count)    // i�� �Է¹��� ���� ���� ��
            break;         // �ݺ����� ����

        i++;
    }

    return 0;
}
