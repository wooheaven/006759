#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    char c1;

    printf("���ڸ� �Է��ϼ���: ");
    scanf("%c", &c1);    // ���ڸ� �Է¹޾Ƽ� ������ ����

    printf("%c\n", c1);    // ������ ������ ���

    return 0;
}
