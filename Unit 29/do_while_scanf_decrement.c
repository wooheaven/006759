#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    do    // ó�� �� ���� �Ʒ� �ڵ尡 �����
    {
        printf("Hello, world! %d\n", count);    // Hello, world!�� i�� ���� �Բ� ���
        count--;                                // count�� 1�� ���ҽ�Ŵ
    } while (count > 0);                        // count�� 0���� Ŭ �� �ݺ�

    return 0;
}
