#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcat �Լ��� ����� ��� ����

int main()
{
    char s1[10] = "world";
    char s2[20] = "Hello"; // s2 �ڿ� ���� ���̹Ƿ� �迭 ũ�⸦ ũ�� ����

    strcat(s2, s1);        // s2 �ڿ� s1�� ����

    printf("%s\n", s2);    // Helloworld

    return 0;
}
