#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    void *ptr = &numArr[2];    // �� ��° ����� �޸� �ּ�

    printf("%d\n", *(int *)ptr);    // 33: ������ ������ ���� ���� ���¿��� ������

    // void �����͸� �ٸ� �����ͷ� ��ȯ�Ͽ� ������ ������ �� �� ������
    printf("%d\n", *((int *)ptr + 1));    // 44
    printf("%d\n", *((int *)ptr - 1));    // 22

    printf("%d\n", *(++(int *)ptr));      // 44
    printf("%d\n", *(--(int *)ptr));      // 33

    printf("%d\n", *(((int *)ptr)++));    // 33
    printf("%d\n", *(((int *)ptr)--));    // 44

    return 0;
}
