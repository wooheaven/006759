#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 }; // ũ�Ⱑ 10�� int�� �迭

    for (int i = sizeof(numArr) / sizeof(int) - 1; i >= 0; i--)   // ��� ���� - 1���� �������� �ݺ�
    {
        printf("%d\n", numArr[i]);    // �迭�� �ε����� �ݺ����� ���� i�� ����
    }

    return 0;
}
