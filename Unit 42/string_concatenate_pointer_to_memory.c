#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcat �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    char *s1 = "world";                      // ���ڿ� ������
    char *s2 = malloc(sizeof(char) * 20);    // char 20�� ũ�⸸ŭ ���� �޸� �Ҵ�

    strcpy(s2, "Hello");   // s2�� Hello ���ڿ� ����

    strcat(s2, s1);        // s2 �ڿ� s1�� ����

    printf("%s\n", s2);    // Helloworld

    free(s2);    // ���� �޸� ����

    return 0;
}
