#include <stdio.h>

void printArray(int *arr, int count)    // �Ű������� �����ͷ� �����Ͽ� �迭�� ����
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printArray(numArr, sizeof(numArr) / sizeof(int));    // �迭�� ����� ������ ����

    return 0;
}
