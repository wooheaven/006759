#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcat �Լ��� ����� ��� ����

int main()
{
    char *s1 = "world";    // ���ڿ� ������
    char *s2 = "Hello";    // ���ڿ� ������

    strcat(s2, s1);    // ���� ����

    printf("%s\n", s1);

    return 0;
}
