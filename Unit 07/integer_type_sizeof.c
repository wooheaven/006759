#include <stdio.h>

int main()
{
    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),        // 1: sizeof�� char �ڷ����� ũ�⸦ ����
        sizeof(short),       // 2: sizeof�� short �ڷ����� ũ�⸦ ����
        sizeof(int),         // 4: sizeof�� int �ڷ����� ũ�⸦ ����
        sizeof(long),        // 4: sizeof�� long �ڷ����� ũ�⸦ ����
        sizeof(long long)    // 8: sizeof�� long long �ڷ����� ũ�⸦ ����
        );

    return 0;
}
