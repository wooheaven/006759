#define __USE_MINGW_ANSI_STDIO 1    // Dev-C++(MinGW)���� %hhu�� ����ϱ� ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    unsigned char flag = 16;
    unsigned char num1, num2;

    scanf("%hhu %hhu", &num1, &num2);

    /*___________________
    _____________________
    ___________________*/

    printf("%u\n", flag);

    return 0;
}
