#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

union Box {    // ����ü ����
    short candy;
    float snack;
    char doll[8];
} b1;          // ����ü�� �����ϴ� ���ÿ� ���� b1 ����

int main()
{
    printf("%d\n", sizeof(b1));  // 8: ����ü�� ��ü ũ��� ���� ū �ڷ����� ũ��

    strcpy(b1.doll, "bear");     // doll�� ���ڿ� bear ����

    printf("%d\n", b1.candy);    // 25954
    printf("%f\n", b1.snack);    // 4464428256607938511036928229376.000000
    printf("%s\n", b1.doll);     // bear

    return 0;
}
