#include <stdio.h>

struct Flags {
    unsigned int a : 1;    // a�� 1��Ʈ ũ��
    unsigned int b : 3;    // b�� 3��Ʈ ũ��
    unsigned int c : 7;    // c�� 7��Ʈ ũ��
};

int main()
{
    struct Flags f1;    // ����ü ���� ����

    f1.a = 1;      //   1: 0000 0001, ��Ʈ 1��
    f1.b = 15;     //  15: 0000 1111, ��Ʈ 4��
    f1.c = 255;    // 255: 1111 1111, ��Ʈ 8��

    printf("%u\n", f1.a);    //   1:        1, ��Ʈ 1���� �����
    printf("%u\n", f1.b);    //   7:      111, ��Ʈ 3���� �����
    printf("%u\n", f1.c);    // 127: 111 1111, ��Ʈ 7���� �����

    return 0;
}
