#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    register int num1 = 10;      // ���� num1�� CPU�� �������͸� ���

    printf("%d\n", num1);
    // printf("%p\n", &num1);    // ������ ����. num1�� �޸𸮿� �����Ƿ� �޸� �ּҸ� ���� �� ����
                                 // error C2103: �������� ������ '&'��(��) �ֽ��ϴ�.

    register int *numPtr = malloc(sizeof(int));

    // �������� ������ �޸� �ּҴ� ������ �� �����Ƿ� ������ �����ڸ� ����� �� ����
    *numPtr = 20;
    printf("%d\n", *numPtr);     // 20

    free(numPtr);

    return 0;
}
