#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2;

    num2 = num1 == 10 ? 100 : 200; // num1�� 10�̸� num2�� 100�� �Ҵ�, 10�� �ƴϸ� num2�� 200�� �Ҵ�

    printf("%d\n", num2);    // 100: num1�� 10�̹Ƿ� num2���� 100�� �Ҵ��

    return 0;
}
