#include "calc.h"     // add, sub �Լ��� ����� ��� ����. calcdata.h ��� ������ �����ϰ� ����
#include "print.h"    // print �Լ��� ����� ��� ����. calcdata.h ��� ������ �����ϰ� ����

int main()
{
    CALC_DATA data1;
    data1.operand1 = 10;
    data1.operand2 = 20;

    add(&data1);      // ���� ����
    print(&data1);    // 10 + 20 = 30

    CALC_DATA data2;
    data2.operand1 = 40;
    data2.operand2 = 15;

    sub(&data2);      // ���� ����
    print(&data2);    // 40 - 15 = 25

    return 0;
}
