#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>    // sprintf �Լ��� ����� ��� ����

int main()
{
    char s1[10];                // ��ȯ�� ���ڿ��� ������ �迭
    float num1 = 38.972340f;    // 38.972340�� �Ǽ�

    sprintf(s1, "%f", num1);    // %f�� �����Ͽ� �Ǽ��� ���ڿ��� ����

    printf("%s\n", s1);         // 38.972340

    return 0;
}
