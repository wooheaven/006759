#include <stdio.h>

struct Flags {
    unsigned int a : 1;    // a�� 1��Ʈ ũ��
    unsigned int b : 3;    // b�� 3��Ʈ ũ��
    unsigned int c : 7;    // c�� 7��Ʈ ũ��
};

int main()
{
    printf("%d", sizeof(struct Flags));    // 4: ����� unsigned int�� ���������Ƿ� 4

    return 0;
}
