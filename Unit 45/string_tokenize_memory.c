#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strtok �Լ��� ����� ��� ����

int main()
{
    char *s1 = malloc(sizeof(char) * 30);    // char 30�� ũ�⸸ŭ ���� �޸� �Ҵ�

    strcpy(s1, "The Little Prince");   // s1�� ���ڿ� ����

    char *ptr = strtok(s1, " ");       // ���� �޸𸮿� ����ִ� ���ڿ��� �ڸ� �� ����

    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    free(s1);    // ���� �޸� ����

    return 0;
}
