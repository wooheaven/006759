#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    for (int i = count; i > 0; i--)    // �Է¹��� ���� ���ҽ�Ű�鼭 �ݺ�
    {
        printf("Hello, world! %d\n", i);
    }

    return 0;
}
