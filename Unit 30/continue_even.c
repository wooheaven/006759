#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);    // ���� �Է¹���

    for (int i = 1; i <= count; i++)    // 1���� �����ϸ鼭 count���� �۰ų� ���� ������ �ݺ�
    {
        if (i % 2 != 0)                 // i�� 2�� �������� �� �������� 0�� �ƴϸ� Ȧ��
            continue;                   // �Ʒ� �ڵ带 �������� �ʰ� �ǳʶ�

        printf("%d\n", i);
    }

    return 0;
}
