#include <stdio.h>

struct Flags {
    union {    // �͸� ����ü
        struct {    // �͸� ����ü
            unsigned short a : 3;    // a�� 3��Ʈ ũ��
            unsigned short b : 2;    // b�� 2��Ʈ ũ��
            unsigned short c : 7;    // c�� 7��Ʈ ũ��
            unsigned short d : 4;    // d�� 4��Ʈ ũ��
        };                           // �հ� 16��Ʈ
        unsigned short e;    // 2����Ʈ(16��Ʈ)
    };
};

int main()
{
    struct Flags f1 = { 0, };    // ��� ����� 0���� �ʱ�ȭ

    f1.a = 4;     //  4: 0000 0100
    f1.b = 2;     //  2: 0000 0010
    f1.c = 80;    // 80: 0101 0000
    f1.d = 15;    // 15: 0000 1111

    printf("%u\n", f1.e);    // 64020: 1111 1010000 10 100

    return 0;
}
