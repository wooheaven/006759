#include <stdio.h>

#define DEBUG    // DEBUG ��ũ�� ����

int main()
{
#ifdef DEBUG     // DEBUG ��ũ�ΰ� ���ǵǾ� �ִٸ� #ifdef, #endif ������ �ڵ带 ������
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    return 0;
}
