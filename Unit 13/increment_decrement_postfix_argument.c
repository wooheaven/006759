#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2 = 2;

    printf("%d %d\n", num1++, num2--);    // 2 2: num1, num2�� ���� ���� ����� �� ���� ������ ����
    printf("%d %d\n", num1, num2);        // 3 1: ���� �����ڰ� ������ ���

    return 0;
}
