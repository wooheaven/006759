#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };    // ũ�Ⱑ 10�� int�� �迭

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)    // �迭�� ��� ������ŭ �ݺ�
    {
        numArr[i] *= 2;    // �迭�� ��ҿ� 2�� ���ؼ� �ٽ� ��ҿ� ����
    }

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)    // �迭�� ��� ������ŭ �ݺ�
    {
        printf("%d\n", numArr[i]);
    }

    return 0;
}
