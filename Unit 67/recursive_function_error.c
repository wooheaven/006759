#include <stdio.h>

void hello()
{
    printf("Hello, world!\n");

    hello();    // hello �Լ� �ȿ��� hello �Լ� ȣ��
}

int main()
{
    hello();    // hello �Լ� ���� ȣ��

    return 0;
}
