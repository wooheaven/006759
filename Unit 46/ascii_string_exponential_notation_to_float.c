#include <stdio.h>
#include <stdlib.h>    // atof �Լ��� ����� ��� ����

int main()
{
    char *s1 = "3.e5";   // "3.e5"�� ���ڿ�
    float num1;

    num1 = atof(s1);     // ���ڿ��� �Ǽ��� ��ȯ�Ͽ� num1�� �Ҵ�

    printf("%e %f\n", num1, num1);    // 3.000000e+05 300000.000000

    return 0;
}
