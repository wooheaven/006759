#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>     // sprintf �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    char *s1 = malloc(sizeof(char) * 20);  // char 20�� ũ�⸸ŭ ���� �޸� �Ҵ�

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"�� ������ �����Ͽ� s1�� ����

    printf("%s\n", s1);    // Hello, world!: ���ڿ� s1 ���

    free(s1);    // ���� �޸� ����

    return 0;
}
