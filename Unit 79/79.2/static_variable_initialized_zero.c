#include <stdio.h>

static int num1;    // ���� ������ �ʱ갪�� �������� ������ 0�� ��(���� ����)

int main()
{
    static int num2;     // ���� ������ �ʱ갪�� �������� ������ 0�� ��(���� ����)

    printf("%d\n", num1);    // 0
    printf("%d\n", num2);    // 0

    return 0;
}
