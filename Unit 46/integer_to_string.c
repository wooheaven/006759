#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>    // sprintf �Լ��� ����� ��� ����

int main()
{
    char s1[10];       // ��ȯ�� ���ڿ��� ������ �迭
    int num1 = 283;    // 283�� ����

    sprintf(s1, "%d", num1);    // %d�� �����Ͽ� ������ ���ڿ��� ����

    printf("%s\n", s1);         // 283

    return 0;
}
