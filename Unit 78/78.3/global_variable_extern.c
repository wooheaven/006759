#include <stdio.h>

extern int num1;    // ������ ����Ǿ� �ִٴ� ���� �̸� �˷���

int main()
{
    printf("%d\n", num1);    // 10

    return 0;
}

int num1 = 10;    // ���� ������ �Լ� �Ʒ��� ����
