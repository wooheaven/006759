#include <stdio.h>

void helloString(char *s1)    // ��ȯ�� ����, char ������ �Ű����� �� �� ����
{
    printf("Hello, %s\n", s1);    // Hello, �� �Ű������� �����Ͽ� ���ڿ� ���
}

int main()
{
    helloString("world!");    // Hello, world!: �Լ��� ȣ���� �� ���ڿ��� ����

    return 0;
}
