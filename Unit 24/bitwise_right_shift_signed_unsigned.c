#include <stdio.h>

int main()
{
    unsigned char num1 = 131;    //  131: 1000 0011
    char num2 = -125;            // -125: 1000 0011

    unsigned char num3;
    char num4;

    num3 = num1 >> 5;    // num1�� ��Ʈ ���� ���������� 5�� �̵�
    num4 = num2 >> 5;    // num2�� ��Ʈ ���� ���������� 5�� �̵�

    printf("%u\n", num3);    //  4: 0000 0100: �� ���� 11�� ������� 0000 0100�� ��
    printf("%d\n", num4);    // -4: 1111 1100: ���ڶ�� ������ ��ȣ ��Ʈ�� ���� 1�� ä�����Ƿ� 
                             // 1111 1100�� ��

    return 0;
}
