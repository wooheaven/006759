#include <stdio.h>
#include <stdlib.h>    // strtof �Լ��� ����� ��� ����

int main()
{
    char *s1 = "35.283672 3.e5 9.281772 7.e-5";    // "35.283672 3.e5f 9.2817721 7.e-5f"�� ���ڿ�
    float num1;
    float num2;
    float num3;
    float num4;
    char *end;    // ���� ������ �� �κ��� �����ϱ� ���� ������

    num1 = strtof(s1, &end);     // ���ڿ��� �Ǽ��� ��ȯ
    num2 = strtof(end, &end);    // ���ڿ��� �Ǽ��� ��ȯ
    num3 = strtof(end, &end);    // ���ڿ��� �Ǽ��� ��ȯ
    num4 = strtof(end, NULL);    // ���ڿ��� �Ǽ��� ��ȯ

    printf("%f\n", num1);    // 35.283672
    printf("%e\n", num2);    // 3.000000e+05
    printf("%f\n", num3);    // 9.281772
    printf("%e\n", num4);    // 7.000000e-05

    return 0;
}
