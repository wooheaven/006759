#include <stdio.h>

// hello�� x�� �ٿ��� ȣ���ϴ� EXECUTER ��ũ�� ����
#define EXECUTER(x) hello##x()

void hello1()
{
    printf("hello 1\n");
}

void hello2()
{
    printf("hello 2\n");
}

int main()
{
    EXECUTER(1);    // hello1 �Լ� ȣ��

    EXECUTER(2);    // hello2 �Լ� ȣ��

    return 0;
}
