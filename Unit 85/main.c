#include <stdio.h>

int main()
{
    int num1 = 20;     // int�� ���� ����
    int *numPtr;       // int�� ������ ����

    numPtr = &num1;    // num1�� �޸� �ּҸ� ���Ͽ� numPtr�� �Ҵ�

    printf("%p\n", numPtr);    // 00000079B575FDA4
                               // numPtr�� ����� �޸� �ּ� ���(��ǻ�͸���, ������ ������ �޶���)

    return 0;
}
