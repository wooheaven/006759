#include <stdio.h>

int main()
{
    char num1 = 67;    // 67: 0100 0011
    char num2;

    num2 = num1 >> 5;    // num1�� ��Ʈ ���� ���������� 5�� �̵�

    printf("%d\n", num2);    // 2: 0000 0010: ���ڶ�� ������ ��ȣ ��Ʈ�� ���� 0���� ä�����Ƿ� 
                             // 0000 0010�� ��

    return 0;
}
