#include <stdio.h>

int main()
{
    int num1 = 10;
    char c1 = 'a';
    int *numPtr1 = &num1;
    char *cPtr1 = &c1;

    void *ptr;        // void ������ ����

                      // ������ �ڷ����� �޶� ������ ��� �߻����� ����
    ptr = numPtr1;    // void �����Ϳ� int ������ ����
    ptr = cPtr1;      // void �����Ϳ� char ������ ����

                      // ������ �ڷ����� �޶� ������ ��� �߻����� ����
    numPtr1 = ptr;    // int �����Ϳ� void ������ ����
    cPtr1 = ptr;      // char �����Ϳ� void ������ ����

    return 0;
}
