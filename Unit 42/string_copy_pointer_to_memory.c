#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    char *s1 = "Hello";                      // ���ڿ� ������
    char *s2 = malloc(sizeof(char) * 10);    // char 10�� ũ�⸸ŭ ���� �޸� �Ҵ�

    strcpy(s2, s1);        // s1�� ���ڿ��� s2�� ����

    printf("%s\n", s2);    // Hello

    free(s2);    // ���� �޸� ����

    return 0;
}
