#include <stdio.h>

int main()
{
    int *numPtr;      // ������ ���� ����
    int num1 = 10;    // ������ ������ �����ϰ� 10 ����

    numPtr = &num1;   // num1�� �޸� �ּҸ� ������ ������ ����

    printf("%d\n", *numPtr);    // 10: ������ �����ڷ� num1�� �޸� �ּҿ� �����Ͽ� ���� ������

    return 0;
}
