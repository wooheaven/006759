#include <stdio.h>

int main()
{
    float num1 = 0.1f;
    char c1 = 'a';

    if (num1 >= 0.09f)   // num1�� �Ǽ� 0.09���� ũ�ų� ������ �˻�
        printf("0.09���� ũ�ų� �����ϴ�.\n");

    if (c1 == 'a')       // c1�� ���� a�� ������ �˻�
        printf("a�Դϴ�.\n");

    if (c1 == 97)        // c1�� ���� 97�� ������ �˻�
        printf("97�Դϴ�.\n");

    if (c1 < 'b')        // c1�� ���� b���� ������ �˻�
        printf("b���� �۽��ϴ�.\n");

    return 0;
}
