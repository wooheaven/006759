#include <stdio.h>

int main()
{
    int num1 = 5;
    int num2;

    if (num1)          // num1�� ���̸� 
        num2 = 100;    // num2�� 100�� �Ҵ�
    else               // num1�� �����̸�
        num2 = 200;    // num2�� 200�� �Ҵ�

    printf("%d\n", num2);    // 100: num1�� 5�̹Ƿ� ��. num2���� 100�� �Ҵ��

    return 0;
}
