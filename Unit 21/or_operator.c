#include <stdio.h>

int main()
{
    printf("%d\n", 1 || 1);    // 1: 1 OR 1�� ��
    printf("%d\n", 1 || 0);    // 1: 1 OR 0�� ��
    printf("%d\n", 0 || 1);    // 1: 0 OR 1�� ��
    printf("%d\n", 0 || 0);    // 0: 0 OR 0�� ����

    printf("%d\n", 2 || 3);    // 1: 2 OR 3�� ��

    return 0;
}
