#include <stdio.h>

float onePointOne()    // ��ȯ���� float���� onePointOne �Լ� ����
{
    return 1.1f;    // �Ǽ� 1.1�� ��ȯ
}

int main()
{
    int num1;

    num1 = (int)onePointOne();    // onePointOne�� ��ȯ���� int�� ��ȯ�Ͽ� ����

    printf("%d\n", num1);    // 1

    return 0;
}
