#define _CRT_SECURE_NO_WARNINGS // strtok ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h> // strtok �Լ��� ����� ��� ����

int main()
{
    char *s1 = "The Little Prince";   // �����Ϳ� ���ڿ� ���ͷ� "You Can Advance"�� �ּ� ����

    char *ptr = strtok(s1, " ");      // ���� ����

    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}
