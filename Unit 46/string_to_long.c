#include <stdio.h>
#include <stdlib.h>    // strtol �Լ��� ����� ��� ����

int main()
{
    char *s1 = "0xaf10";    // "0xaf10"�� ���ڿ�
    int num1;

    num1 = strtol(s1, NULL, 16);    // 16�������� ǥ��� ���ڿ��� ������ ��ȯ

    printf("%x %d\n", num1);        // af10 44816

    return 0;
}
