#include <stdio.h>

int main()
{
    int i = 100;
    while (i > 0)    // i�� 0���� Ŭ �� �ݺ�. 100���� 1���� �����ϸ鼭 100�� �ݺ�
    {
        printf("Hello, world! %d\n", i);    // Hello, world!�� i�� ���� �Բ� ���
        i--;                                // i�� 1�� ���ҽ�Ŵ
    }

    return 0;
}
