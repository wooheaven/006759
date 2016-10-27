#include <stdio.h>

int main()
{
    float num1 = 3.e5f;             // ���� ǥ������� 300000�� ǥ��
                                    // float�� ���� �ڿ� f�� ����

    double num2 = -1.3827e-2;       // ���� ǥ������� -0.013827�� ǥ��
                                    // double�� ���� �ڿ� �ƹ��͵� ������ ����

    long double num3 = 5.21e+9l;    // ���� ǥ������� 5210000000�� ǥ��
                                    // long double�� ���� �ڿ� l�� ����

    // float�� double�� %f�� ���, long double�� %Lf�� ���
    printf("%f %f %Lf\n", num1, num2, num3);    // 300000.000000 -0.013827 5210000000.000000

    // ���� ǥ������� ����� ���� float�� double�� %e�� ���, long double�� %Le�� ���
    printf("%e %e %Le\n", num1, num2, num3);    // 3.000000e+05 -1.382700e-02 5.210000e+09

    return 0;
}
