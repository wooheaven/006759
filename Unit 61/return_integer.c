#include <stdio.h>

int one()    // ��ȯ���� int���� one �Լ� ����
{
    return 1;    // 1�� ��ȯ
}

int main()
{
    int num1;

    num1 = one();    // int���� ��ȯ�����Ƿ� int�� ������ ����

    printf("%d\n", num1);    // 1

    return 0;
}
