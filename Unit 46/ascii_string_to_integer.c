#include <stdio.h>
#include <stdlib.h>    // atoi �Լ��� ����� ��� ����

int main()
{
    char *s1 = "283";   // "283"�� ���ڿ�
    int num1;

    num1 = atoi(s1);        // ���ڿ��� ������ ��ȯ�Ͽ� num1�� �Ҵ�

    printf("%d\n", num1);   // 283

    return 0;
}
