#include <stdio.h>

int *ten()    // int �����͸� ��ȯ�ϴ� ten �Լ� ����
{
    int num1 = 10;   // num1�� �Լ� ten�� ������ �����

    return &num1;    // �Լ����� ���� ������ �ּҸ� ��ȯ�ϴ� ���� �߸��� ���
}

int main()
{
    int* numPtr;

    numPtr = ten();    // �Լ��� ȣ���ϰ� ��ȯ���� numPtr�� ����

    printf("%d\n", *numPtr);    // 10: ���� ������ ������ �̹� ����� ������ ����ϰ� ����

    return 0;
}
