#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>    // sprintf �Լ��� ����� ��� ����

int main()
{
    char s1[20];                // ��ȯ�� ���ڿ��� ������ �迭
    float num1 = 38.972340f;    // 38.972340�� �Ǽ�

    sprintf(s1, "%e", num1);    // %e�� �����Ͽ� �Ǽ��� ���� ǥ������� �� ���ڿ��� ����

    printf("%s\n", s1);         // 3.897234e+01

    return 0;
}
