#include <stdio.h>

int one()    // ��ȯ���� int���� one �Լ� ����
{
    float a = 1.1f;

    return (int)a;    // a�� int�� ��ȯ�Ͽ� ��ȯ
}

int main()
{
    int num1;

    num1 = one();    // int���� ��ȯ�����Ƿ� int�� ������ ����

    printf("%d\n", num1);    // 1

    return 0;
}
