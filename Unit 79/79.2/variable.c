#include <stdio.h>

void increaseNumber()
{
    int num1 = 0;    // ���� ���� �� �� �ʱ�ȭ

    printf("%d\n", num1);    // ���� num1�� ���� ���

    num1++;    // ������ ���� 1�� ����
}

int main()
{
    increaseNumber();    // 0
    increaseNumber();    // 0
    increaseNumber();    // 0
    increaseNumber();    // 0: ������ �Ź� �����ǰ� ������Ƿ� 0�� ��µ�

    return 0;
}
