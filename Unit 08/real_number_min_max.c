#include <stdio.h>
#include <float.h>    // �Ǽ� �ڷ����� ��� �ּڰ�, �ִ��� ���ǵ� ��� ����

int main()
{
    float num1 = FLT_MIN;           // float�� ��� �ּڰ�
    float num2 = FLT_MAX;           // float�� ��� �ִ�
    double num3 = DBL_MIN;          // dobule�� ��� �ּڰ�
    double num4 = DBL_MAX;          // double�� ��� �ִ�
    long double num5 = LDBL_MIN;    // long double�� ��� �ּڰ�
    long double num6 = LDBL_MAX;    // long double�� ��� �ִ�

    printf("%.40f %.2f\n", num1, num2);    // 0.0000000000000000000000000000000000000118
                                           // 340282346638528859811704183484516925440.00

    printf("%e %e\n", num3, num4);         // 2.225074e-308 1.797693e+308
    printf("%Le %Le\n", num5, num6);       // 2.225074e-308 1.797693e+308

    return 0;
}
