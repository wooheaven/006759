#include <stdio.h>

int main()
{
    unsigned char num1 = 3;     //  3: 0000 0011
    unsigned char num2 = 24;    // 24: 0001 1000

    printf("%u\n", num1 << 3);    // 24: 0001 1000: num1�� ��Ʈ ���� �������� 3�� �̵�
    printf("%u\n", num2 >> 2);    //  6: 0000 0110: num2�� ��Ʈ ���� ���������� 2�� �̵�

    return 0;
}
