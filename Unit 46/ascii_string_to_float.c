#include <stdio.h>
#include <stdlib.h> // atof �Լ��� ����� ��� ����

int main()
{
    char *s1 = "35.283672";  // "35.283672"�� ���ڿ�
    float num1;

    num1 = atof(s1);         // ���ڿ��� �Ǽ��� ��ȯ�Ͽ� num1�� �Ҵ�

    printf("%f\n", num1);    // 35.283672

    return 0;
}
