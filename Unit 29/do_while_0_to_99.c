#include <stdio.h>

int main()
{
    int i = 0;

    do     // ó�� �� ���� �Ʒ� �ڵ尡 �����
    {
        printf("Hello, world! %d\n", i);    // Hello, world!�� i�� ���� �Բ� ���
        i++;                                // i�� 1�� ������Ŵ
    } while (i < 100);    // i�� 100���� ���� �� �ݺ�. 0���� 99���� �����ϸ鼭 100�� �ݺ�

    return 0;
}
