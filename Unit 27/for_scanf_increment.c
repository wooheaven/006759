#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    for (int i = 0; i < count; i++)    // 0���� �Է¹��� ������ ���� ������ �ݺ�
    {
        printf("Hello, world! %d\n", i);
    }

    return 0;
}
