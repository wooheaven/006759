#include <stdio.h>

int main()
{
    char buffer[100];

    gets_s(buffer, sizeof(buffer));    // ǥ�� �Է¿��� ���ڿ��� �Է¹���
                                       // Visual Studio 2015

    puts(buffer);    // ���ڿ��� ȭ��(ǥ�� ���)�� ���

    return 0;
}
