#include <stdio.h>

int main()
{
    char *s1 = "Hello";       // �����Ϳ� ���ڿ� Hello�� �ּ� ����

    printf("%c\n", s1[1]);    // e: �ε��� 1(�� ��°)�� ���� ���
    printf("%c\n", s1[4]);    // o: �ε��� 4(�ټ� ��°)�� ���� ���
    printf("%c\n", s1[5]);    // ���ڿ� �� ���� NULL(\0) ���. NULL�� ȭ�鿡 ǥ�õ��� ����

    return 0;
}
