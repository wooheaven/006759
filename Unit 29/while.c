#include <stdio.h>

int main()
{
    int i = 0;

    // do�� �ش��ϴ� �κ�
    printf("Hello, world! %d\n", i);    // ó�� �� ���� ����
    i++;                                // ó�� �� ���� ����

    while (i < 100)    // i�� 100���� ���� �� �ݺ�. 0���� 99���� �����ϸ鼭 100�� �ݺ�
    {
        printf("Hello, world! %d\n", i);    // Hello, world!�� i�� ���� �Բ� ���
        i++;                                // i�� 1�� ������Ŵ
    }

    return 0;
}
