#include <stdio.h>

void helloNumber(int num1)    // ��ȯ�� ����, int�� �Ű����� �� �� ����
{
    printf("Hello, %d\n", num1);    // Hello, �� �Ű������� �����Ͽ� ���ڿ� ���
}

int main()
{
    helloNumber(10);    // Hello, 10: helloNumber�� 10�� �־ ȣ��
    helloNumber(20);    // Hello, 20: helloNumber�� 20�� �־ ȣ��

    return 0;
}
