#include <stdio.h>

int main()
{
    float num1 = 0.0f;
    float num2 = 0.1f;

    // 0.1�� 10�� ����
    for (int i = 0; i < 10; i++)
    {
        num1 = num1 + num2;
    }

    printf("%.15f\n", num1);    // 1.000000119209290: 1.0�� ���;� ������ �ݿø� ���� �߻�

    return 0;
}
