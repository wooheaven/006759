#include <stdio.h>

int main()
{
    char s1[10];    // ���� 10�� ũ���� �迭 ����

    for (int i = 0; i < 10; i++)    // �迭 ũ�⸸ŭ �ݺ�
    {
        s1[i] = 97 + i;
    }

    for (int i = 0; i < 10; i++)    // �迭 ũ�⸸ŭ �ݺ�
    {
        printf("%c ", s1[i]);
    }

    return 0;
}
