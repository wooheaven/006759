#include <stdio.h>

extern int num1;    // �ٸ� �ҽ� ����(�ܺ�)�� �ִ� ���� ���� ������ extern���� ����� �� ����
                    // ������ ����

int main()
{
    printf("%d\n", num1);    // ���� ���� ���� num1�� �� ���

    return 0;
}
