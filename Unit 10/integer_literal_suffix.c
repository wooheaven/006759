#include <stdio.h>

int main()
{
    printf("%ld\n", -10L);                       // long ũ���� ���� ���ͷ�
    printf("%lld\n", -1234567890123456789LL);    // long long ũ���� ���� ���ͷ�

    printf("%u\n", 10U);                         // unsigned int ũ���� ���� ���ͷ�
    printf("%lu\n", 1234567890UL);               // unsigned long ũ���� ���� ���ͷ�

    printf("%lu\n", 10UL);                       // unsigned long ũ���� ���� ���ͷ�
    printf("%llu\n", 1234567890123456789ULL);    // unsigned long long ũ���� ���� ���ͷ�

    return 0;
}
