#include <stdio.h>

void hello()    // ��ȯ���� �Ű������� ����
{
    printf("Hello, world!\n");
}

void bonjour()    // ��ȯ���� �Ű������� ����
{
    printf("bonjour le monde!\n");
}

int main()
{
    void (*fp)();   // ��ȯ���� �Ű������� ���� �Լ� ������ fp ����

    fp = hello;     // hello �Լ��� �޸� �ּҸ� �Լ� ������ fp�� ����
    fp();           // Hello, world!: �Լ� �����ͷ� hello �Լ� ȣ��

    fp = bonjour;   // bonjour �Լ��� �޸� �ּҸ� �Լ� ������ fp�� ����
    fp();           // bonjour le monde!: �Լ� �����ͷ� bonjour �Լ� ȣ��

    return 0;
}
