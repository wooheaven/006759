#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };    // ũ�Ⱑ 10�� int�� �迭

    printf("%d\n", sizeof(numArr));                   // 40: 4����Ʈ ũ���� ��Ұ� 10���̹Ƿ� 40
    printf("%d\n", sizeof(numArr) / sizeof(int));     // 10: �迭�� ũ�⸦ ���� ����
                                                      // ��ü ������ ����� ũ��� ������

    return 0;
}
