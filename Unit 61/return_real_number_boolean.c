#include <stdio.h>
#include <stdbool.h>    // bool, true, false�� ���ǵ� ��� ����

float realNumber()    // ��ȯ���� float���� realNumber �Լ� ����
{
    return 1.234567f;    // 1.234567: float���� ��ȯ
}

bool truth()    // ��ȯ���� bool���� truth �Լ� ����
{
    return true;    // true: bool���� ��ȯ
}

int main()
{
    float num1;
    bool b1;

    num1 = realNumber();    // float���� ��ȯ�����Ƿ� float�� ������ ����
    b1 = truth();           // bool���� ��ȯ�����Ƿ� bool�� ������ ����

    printf("%f\n", num1);   // 1.234567
    printf("%d\n", b1);     // 1

    return 0;
}
