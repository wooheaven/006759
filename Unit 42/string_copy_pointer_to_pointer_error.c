#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

int main()
{
    char *s1 = "Hello";    // ���ڿ� ������
    char *s2 = "";         // ���ڿ� ������

    strcpy(s2, s1);    // ���� ����

    printf("%s\n", s2);

    return 0;
}
