#include <stdio.h>

struct PacketHeader {
    char flags;    // 1����Ʈ
    int seq;       // 4����Ʈ
} __attribute__((aligned(1), packed));    // GCC 4.0 �̸�: 1����Ʈ ũ��� ����

int main()
{
    struct PacketHeader header;

    printf("%d\n", sizeof(header.flags));     // 1: char�� 1����Ʈ
    printf("%d\n", sizeof(header.seq));       // 4: int�� 4����Ʈ
    printf("%d\n", sizeof(header));           // 5: 1����Ʈ ������ ���������Ƿ� 
                                              // ����ü ��ü ũ��� 5����Ʈ

    return 0;
}
