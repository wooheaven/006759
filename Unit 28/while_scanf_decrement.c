#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    while (count > 0)    // count�� 0���� Ŭ �� �ݺ�
    {
        printf("Hello, world! %d\n", count);
        count--;         // count�� 1�� ���ҽ�Ŵ
    }

    return 0;
}
