#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 0;

    if (num1 /*(1)*/ num1)
        printf("��\n");
    else
        printf("����\n");

    if (num1 /*(2)*/ num2)
        printf("��\n");
    else
        printf("����\n");

    printf("%s\n", !/*(3)*/ ? "��" : "����");

    return 0;
}
