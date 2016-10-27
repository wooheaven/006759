#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

union Box {
    short candy;
    float snack;
    char doll[8];
};

int main()
{
    union Box b1;      // ����ü ���� ����
    union Box *ptr;    // ����ü ������ ����

    ptr = &b1;    // b1�� �޸� �ּҸ� ���Ͽ� ptr�� �Ҵ�

    strcpy(ptr->doll, "bear");     // doll�� ���ڿ� bear ����

    printf("%d\n", ptr->candy);    // 25954
    printf("%f\n", ptr->snack);    // 4464428256607938511036928229376.000000
    printf("%s\n", ptr->doll);     // bear

    return 0;
}
