#include <stdio.h>

#define NDEBUG    // NDEBUG ��ũ�� ����

int main()
{
#ifndef DEBUG     // DEBUG�� ���ǵǾ� ���� ���� �� �ڵ带 ������
    printf("main function\n");
#endif

    return 0;
}
