#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>    // sprintf �Լ��� ����� ��� ����

int main()
{
    char s1[20];    // ũ�Ⱑ 20�� char�� �迭�� ����

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"�� ������ �����Ͽ� s1�� ����

    printf("%s\n", s1);    // Hello, world!: ���ڿ� s1 ���

    return 0;
}
