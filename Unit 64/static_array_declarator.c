#include <stdio.h>

void printArray(int arr[static 5], int count)    // �迭 ����� �ּ� ������ 5���� ����
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int numArr1[5] = { 1, 2, 3, 4, 5 };

    // ��� ������ 5���̹Ƿ� OK
    printArray(numArr1, sizeof(numArr1) / sizeof(int));

    int numArr2[3] = { 1, 2, 3 };

    // ��� ������ 3���̹Ƿ� ���
    printArray(numArr2, sizeof(numArr1) / sizeof(int));

    return 0;
}
