#include "calc.h"    // CALC_DATA ����ü�� ����ϱ� ���� calc.h ��� ���� ����
                     // calc.h�� calcdata.h�� �����ϰ� ����

void add(CALC_DATA *data)    // ���� �Լ� ����
{
    data->operator = '+';    // ������ ���� + ����
    
    // ����� �� �� ���� ���ؼ� ��� ����
    data->result = data->operand1 + data->operand2;
}

void sub(CALC_DATA *data)    // ���� �Լ� ����
{
    data->operator = '-';    // ������ ���� - ����

    // ����� �� �� ���� ���� ���ؼ� ��� ����
    data->result = data->operand1 - data->operand2;
}
