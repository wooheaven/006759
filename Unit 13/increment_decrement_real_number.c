#include <stdio.h>

int main()
{
    float num1 = 2.1f;
    float num2 = 2.1f;

    num1++;    // �Ǽ��� ������ ���� 1 ������Ŵ
    num2--;    // �Ǽ��� ������ ���� 1 ���ҽ�Ŵ

    printf("%f %f\n", num1, num2);    // 3.100000 1.100000

    return 0;
}
