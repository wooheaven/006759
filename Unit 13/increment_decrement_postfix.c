#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2 = 2;
    int num3;
    int num4;

    num3 = num1++;    // num1�� ���� num3�� �Ҵ��� �� num1�� ���� 1 ������Ŵ
    num4 = num2--;    // num2�� ���� num4�� �Ҵ��� �� num2�� ���� 1 ���ҽ�Ŵ

    printf("%d %d\n", num3, num4);    // 2 2

    return 0;
}
