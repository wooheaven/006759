#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    char s1[10];    // ũ�Ⱑ 10�� char�� �迭�� ����
    char s2[10];    // ũ�Ⱑ 10�� char�� �迭�� ����

    printf("���ڿ��� �� �� �Է��ϼ���: ");
    scanf("%s %s", s1, s2);    // ǥ�� �Է¿��� �������� ���е� ���ڿ� �� ���� �Է¹���

    printf("%s\n", s1);    // s1�� ������ ���
    printf("%s\n", s2);    // s2�� ������ ���

    return 0;
}
