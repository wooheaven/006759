#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    char s1[10];    // ũ�Ⱑ 10�� char�� �迭�� ����

    printf("���ڿ��� �Է��ϼ���: ");
    scanf("%s", s1);     // ǥ�� �Է��� �޾Ƽ� �迭 ������ ���ڿ��� ����

    printf("%s\n", s1);  // ���ڿ��� ������ ���

    return 0;
}
