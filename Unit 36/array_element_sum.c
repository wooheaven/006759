#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };    // ũ�Ⱑ 10�� int�� �迭
    int sum = 0;    // ���� ������ ������ 0���� �ʱ�ȭ

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)    // �迭�� ��� ������ŭ �ݺ�
    {
        sum += numArr[i];    // sum�� �迭�� ��Ҹ� ���ؼ� �ٽ� sum�� ����
    }

    printf("%d\n", sum);    // 605

    return 0;
}
