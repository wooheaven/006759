#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

int main()
{
    char s1[10] = "Hello";    // ũ�Ⱑ 10�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�
    char s2[10];              // ũ�Ⱑ 10�� char�� �迭�� ����

    strcpy(s2, s1);        // s1�� ���ڿ��� s2�� ����

    printf("%s\n", s2);    // Hello

    return 0;
}
