#include <stdio.h>

int main()
{
    long long *numPtr1;    // long long�� ������ ����
    float *numPtr2;        // float�� ������ ����
    char *cPtr1;           // char�� ������ ����

    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';

    numPtr1 = &num1;    // num1�� �޸� �ּ� ����
    numPtr2 = &num2;    // num2�� �޸� �ּ� ����
    cPtr1 = &c1;        // c1�� �޸� �ּ� ����

    printf("%lld\n", *numPtr1);    // 10
    printf("%f\n", *numPtr2);      // 3.500000
    printf("%c\n", *cPtr1);        // a

    return 0;
}
