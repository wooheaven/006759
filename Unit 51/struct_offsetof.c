#include <stdio.h>
#include <stddef.h>   // offsetof ��ũ�ΰ� ���ǵ� ��� ����

struct PacketHeader {
    char flags;    // 1����Ʈ
    int seq;       // 4����Ʈ
};

int main()
{
    printf("%d\n", offsetof(struct PacketHeader, flags));    // 0
    printf("%d\n", offsetof(struct PacketHeader, seq));      // 4

    return 0;
}
