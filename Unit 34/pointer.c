#include <stdio.h>

int main()
{
    int *numPtr;      // ������ ���� ����
    int num1 = 10;    // int�� ������ �����ϰ� 10 ����

    numPtr = &num1;   // num1�� �޸� �ּҸ� ������ ������ ����

    printf("%p\n", numPtr);    // 0055FC24: ������ ���� numPtr�� �� ���
                               // ��ǻ�͸���, ������ ������ �޶���
    printf("%p\n", &num1);     // 0055FC24: ���� num1�� �޸� �ּ� ���
                               // ��ǻ�͸���, ������ ������ �޶���

    return 0;
}
