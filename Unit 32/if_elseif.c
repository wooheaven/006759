#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1;

    scanf("%d", &num1);

    if (num1 == 1)         // num1�� 1�̸�
        printf("1�Դϴ�.\n");
    else if (num1 == 2)    // num1�� 2�̸�
        printf("2�Դϴ�.\n");

    return 0;
}
