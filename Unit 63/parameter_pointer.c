#include <stdio.h>

void swapNumber(int *first, int *second)    // ��ȯ�� ����, int ������ �Ű����� �� �� ����
{
    int temp;    // �ӽ� ���� ����

    // �������� ���� ��������, ���� ������
    temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    swapNumber(&num1, &num2);        // &�� ����Ͽ� num1�� num2�� �޸� �ּҸ� �־���

    printf("%d %d\n", num1, num2);   // 20 10: swapNumber�� ���ؼ� num1�� num2�� ���� ���� �ٲ�

    return 0;
}
