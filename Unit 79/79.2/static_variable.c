#include <stdio.h>

void increaseNumber()
{
    static int num1 = 0;     // ���� ���� ���� �� �� �ʱ�ȭ

    printf("%d\n", num1);    // ���� ���� num1�� ���� ���

    num1++;    // ���� ���� num1�� ���� 1 ������Ŵ
}

int main()
{
    increaseNumber();    // 0
    increaseNumber();    // 1
    increaseNumber();    // 2
    increaseNumber();    // 3: ���� ������ ������� �ʰ� �����ǹǷ� ���� ��� ������

    return 0;
}
