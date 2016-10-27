#include <stdio.h>
#include <stdlib.h>    // strtol �Լ��� ����� ��� ����

int main()
{
    char *s1 = "0xaf10 42 0x27C 9952";    // "0xaf10 42 0x27C 9952"�� ���ڿ�
    int num1;
    int num2;
    int num3;
    int num4;
    char *end;    // ���� ������ �� �κ��� �����ϱ� ���� ������

    num1 = strtol(s1, &end, 16);     // 16�������� ǥ��� ���ڿ��� ������ ��ȯ
    num2 = strtol(end, &end, 10);    // 10�������� ǥ��� ���ڿ��� ������ ��ȯ
    num3 = strtol(end, &end, 16);    // 16�������� ǥ��� ���ڿ��� ������ ��ȯ
    num4 = strtol(end, NULL, 10);    // 10�������� ǥ��� ���ڿ��� ������ ��ȯ

    printf("%x\n", num1);    // af10
    printf("%d\n", num2);    // 42
    printf("%X\n", num3);    // 27C
    printf("%d\n", num4);    // 9952

    return 0;
}
