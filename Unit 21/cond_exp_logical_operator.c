#include <stdio.h>

int main()
{
    int num1 = 20;
    int num2 = 10;
    int num3 = 30;
    int num4 = 15;

    printf("%d\n", num1 > num2 && num3 > num4);    // 1: ���� ��� ���̹Ƿ� ��
    printf("%d\n", num1 > num2 && num3 < num4);    // 0: �ո� ���̹Ƿ� ����

    printf("%d\n", num1 > num2 || num3 < num4);    // 1: �ո� ���̹Ƿ� ��
    printf("%d\n", num1 < num2 || num3 < num4);    // 0: ���� ��� �����̹Ƿ� ����

    printf("%d\n", !(num1 > num2));    // 0: ���� NOT�� ����

    return 0;
}
