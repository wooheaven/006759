#include <stdio.h>

int main()
{
    char *cPtr1 = NULL;
    short *numPtr1 = NULL;
    long long *numPtr2 = NULL;

    printf("%p\n", cPtr1 + 1);      // 00000001: 0x000000���� 1����Ʈ��ŭ ���������� �̵�
    printf("%p\n", numPtr1 + 1);    // 00000002: 0x000000���� 2����Ʈ��ŭ ���������� �̵�
    printf("%p\n", numPtr2 + 1);    // 00000008: 0x000000���� 8����Ʈ��ŭ ���������� �̵�

    return 0;
}
