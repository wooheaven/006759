#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = numArr;    // �迭 ù ��° ����� �ּҸ� �����Ϳ� ����

    numPtrB = numPtrA + 1;    // ������ ����. numPtrA + 4����Ʈ
    numPtrC = numPtrA + 2;    // ������ ����. numPtrA + 8����Ʈ

    printf("%d\n", *numPtrB);    // 22: �������� ���� ������, numArr[1]�� ����
    printf("%d\n", *numPtrC);    // 33: �������� ���� ������, numArr[2]�� ����

    return 0;
}
