#include <stdio.h>

// a�� b�� ���̴� CONCAT ��ũ�� ����
#define CONCAT(a, b) a##b

int main()
{
    printf("%d\n", CONCAT(1, 2));    // 12

    return 0;
}
