#include <stdio.h>

#define DEBUG    // DEBUG ��ũ�� ����
#define TEST     // TEST ��ũ�� ����

int main()
{
    // DEBUG �Ǵ� TEST�� ���ǵǾ� �����鼭 VERSION_10�� ���ǵǾ� ���� ���� ��
#if (defined DEBUG || defined TEST) && !defined (VERSION_10)
    printf("Debug\n");
#endif

    return 0;
}
