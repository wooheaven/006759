#include <stdio.h>

int main()
{
    char s1[10] = "Hello";    // ũ�Ⱑ 10�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�

    printf("%c\n", s1[1]);    // e: �ε��� 1(�� ��°)�� ���� ���
    printf("%c\n", s1[4]);    // o: �ε��� 4(�ټ� ��°)�� ���� ���
    printf("%c\n", s1[5]);    // ���ڿ� �� ���� NULL(\0) ���. NULL�� ȭ�鿡 ǥ�õ��� ����

    return 0;
}
