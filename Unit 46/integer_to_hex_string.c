#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>    // sprintf �Լ��� ����� ��� ����

int main()
{
    char s1[10];      // ��ȯ�� ���ڿ��� ������ �迭
    int num1 = 283;   // 283�� ����

    sprintf(s1, "0x%x", num1);    // %x�� �����Ͽ� ������ 16�������� ǥ��� ���ڿ��� ����
                                  // 16������� ���� ��Ÿ���� ���� �տ� 0x�� ����

    printf("%s\n", s1);           // 0x11b

    return 0;
}
