#include <stdio.h>

#define PRINT_NUM(x) printf("%d\n", x)    // printf("%d\n", x)�� PRINT_NUM(x)�� ����

int main()
{
    PRINT_NUM(10);    // 10: printf("%d\n", 10)

    PRINT_NUM(20);    // 20: printf("%d\n", 20)

    return 0;
}
