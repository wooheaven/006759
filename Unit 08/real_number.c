#include <stdio.h>

int main()
{
    float num1 = 0.1f;               // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
                                     // float�� ���� �ڿ� f�� ����

    double num2 = 3867.215820;       // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
                                     // double�� ���� �ڿ� �ƹ��͵� ������ ����

    long double num3 = 9.327513l;    // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
                                     // long double�� ���� �ڿ� l�� ����

    // float�� double�� %f�� ���, long double�� %Lf�� ���
    printf("%f %f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513

    return 0;
}
