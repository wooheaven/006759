#include <stdio.h>

#define USB    // USB ��ũ�� ����

int main()
{
#ifdef PS2              // PS2�� ���ǵǾ� ���� �� �ڵ带 ������
    printf("PS2\n");
#elif defined USB       // PS2�� ���ǵǾ� ���� �ʰ�, USB�� ���ǵǾ� ���� �� �ڵ带 ������
    printf("USB\n");
#else                   // PS2�� USB�� ���ǵǾ� ���� ���� �� �ڵ带 ������
    printf("�������� �ʴ� ��ġ�Դϴ�.\n");
#endif

    return 0;
}
