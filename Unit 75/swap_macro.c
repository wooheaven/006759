#include <stdio.h>

// ��ũ�� �ȿ��� ������ ������ �� �ֵ��� do while ���
// a�� b�� ���� ���� �ٲ�
#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)

int main()
{
    int num1 = 10;
    int num2 = 20;

    SWAP(num1, num2, int);            // ���� �ٲ� �ڷ������� int�� ����
    printf("%d %d\n", num1, num2);    // 20 10: �� ������ ���� �ٲ�

    float num3 = 1.5f;
    float num4 = 3.8f;

    SWAP(num3, num4, float);          // ���� �ٲ� �ڷ������� float�� ����
    printf("%f %f\n", num3, num4);    // 3.800000 1.500000: �� ������ ���� �ٲ�

    return 0;
}
