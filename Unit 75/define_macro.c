#include <stdio.h>

#define ARRAY_SIZE 10    // 10�� ARRAY_SIZE�� ����

int main()
{
    char s1[ARRAY_SIZE];    // 10 ��� ARRAY_SIZE ��ũ�� ���

    for (int i = 0; i < ARRAY_SIZE; i++)    // 10 ��� ARRAY_SIZE ��ũ�� ���
    {
        s1[i] = 97 + i;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)    // 10 ��� ARRAY_SIZE ��ũ�� ���
    {
        printf("%c ", s1[i]);
    }

    return 0;
}
