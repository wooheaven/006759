#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    int i = 0;
    while (i < count)                      // i�� count���� ���� �� �ݺ�
    {
        printf("Hello, world! %d\n", i);   // Hello, world!�� i�� ���� �Բ� ���
        i++;                               // i�� 1�� ������Ŵ
    }

    return 0;
}
