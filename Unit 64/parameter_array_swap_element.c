#include <stdio.h>

void swapElement(int arr[], int first, int second)    // �迭�� �����Ϳ� �ε����� ����
{
    int temp;

    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    swapElement(numArr, 0, 1);    // �迭�� ���� ���� �ٲ� �ε����� ����

    printf("%d %d\n", numArr[0], numArr[1]); // 2 1: swapElement�� ���ؼ� �迭 ����� ���� ���� �ٲ�

    return 0;
}
