#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    int num1, num2;

    printf("������ �� �� �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);    // ���� �� �� �Է¹޾Ƽ� ���� �� ���� ����

    printf("%d %d\n", num1, num2);    // ������ ������ ���

    return 0;
}
