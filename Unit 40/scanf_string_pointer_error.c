#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main()
{
    char *s1 = "Hello";    // ���ڿ� �����͸� �����ϰ� ���ڿ� �Ҵ�

    printf("���ڿ��� �Է��ϼ���: ");
    scanf("%s", s1);    // ���� ����

    printf("%s\n", s1);

    return 0;
}
