#include <stdio.h>

void helloString(char *s1)    // ��ȯ�� ����, char ������ �Ű����� �� �� ����
{
    printf("Hello, %s\n", s1);    // Hello, �� �Ű������� �����Ͽ� ���ڿ� ���
}

int main()
{
    char s1[10] = "world!";    // �迭 ������ ���ڿ�

    helloString(s1);    // Hello, world!: �Լ��� ȣ���� �� �迭 ����

    return 0;
}
