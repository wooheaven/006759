#include <stdio.h>
#include <string.h>    // strcmp �Լ��� ����� ��� ����

int main()
{
    // aaa�� ASCII �ڵ�� 97 97 97
    // aab�� ASCII �ڵ�� 97 97 98
    // aac�� ASCII �ڵ�� 97 97 99

    printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa�� aaa�� �����Ƿ� 0
    printf("%d\n", strcmp("aab", "aaa"));    //  1: aab�� aaa �߿��� aab�� ũ�Ƿ� 1
    printf("%d\n", strcmp("aab", "aac"));    // -1: aab�� aac �߿��� aac�� ũ�Ƿ� -1

    return 0;
}
