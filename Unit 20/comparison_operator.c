#include <stdio.h>

int main()
{
    int num1 = 10;

    printf("%d\n", num1 == 10);    // 1: num1�� 10�� ������
    printf("%d\n", num1 != 5);     // 1: num1�� 5�� �ٸ���

    printf("%d\n", num1 > 10);     // 0: num1�� 10���� ū��
    printf("%d\n", num1 < 10);     // 0: num1�� 10���� ������

    printf("%d\n", num1 >= 10);    // 1: num1�� 10���� ũ�ų� ������
    printf("%d\n", num1 <= 10);    // 1: num1�� 10���� �۰ų� ������

    return 0;
}
