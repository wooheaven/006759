#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    char *s1 = malloc(sizeof(char) * 10);    // char 10�� ũ�⸸ŭ ���� �޸� �Ҵ�

    printf("���ڿ��� �Է��ϼ���: ");
    scanf("%s", s1);      // ǥ�� �Է��� �޾Ƽ� �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ� ����

    printf("%s\n", s1);   // ���ڿ��� ������ ���

    free(s1);    // ���� �޸� ����

    return 0;
}
