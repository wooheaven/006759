#define _CRT_SECURE_NO_WARNINGS    // strcpy, strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy, strcat �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    char s1[10] = "world";                   // ũ�Ⱑ 10�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�
    char *s2 = malloc(sizeof(char) * 20);    // char 20�� ũ�⸸ŭ ���� �޸� �Ҵ�

    strcpy(s2, "Hello");    // s2�� Hello ���ڿ� ����

    strcat(s2, s1);         // s2 �ڿ� s1�� ����

    printf("%s\n", s2);     // Helloworld

    free(s2);    // ���� �޸� ����

    return 0;
}
