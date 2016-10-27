#include <stdio.h>

struct PacketHeader {
    char flags;    // 1����Ʈ
    int seq;       // 4����Ʈ
};

int main()
{
    struct PacketHeader header;

    printf("%d\n", sizeof(header.flags));           // 1: char�� 1����Ʈ
    printf("%d\n", sizeof(header.seq));             // 4: int�� 4����Ʈ
    printf("%d\n", sizeof(header));                 // 8: ����ü ��ü ũ��� 8����Ʈ
    printf("%d\n", sizeof(struct PacketHeader));    // 8: ����ü �̸����� ũ�� ���ϱ�

    return 0;
}
