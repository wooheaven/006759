#include <stdio.h>
#include <string.h>    // strcmp �Լ��� ����� ��� ����

int main()
{
    char s1[10] = "Hello";
    char *s2 = "Hello";

    int ret = strcmp(s1, s2);    // �� ���ڿ��� ������ ���ڿ� ��

    printf("%d\n", ret);         // 0: �� ���ڿ��� ������ 0

    return 0;
}
