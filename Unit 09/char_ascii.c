#include <stdio.h>

int main()
{
    char c1 = 97;    // a�� ASCII �ڵ尪 97 ����
    char c2 = 98;    // b�� ASCII �ڵ尪 98 ����

    // char�� %c�� ����ϸ� ���ڰ� ��µǰ�, %d�� ����ϸ� �������� ��µ�
    printf("%c, %d\n", c1, c1);    // a, 97
    printf("%c, %d\n", c2, c2);    // b, 98

    return 0;
}
