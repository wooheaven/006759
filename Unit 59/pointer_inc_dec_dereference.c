#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;
    int *numPtrB;
    int *numPtrC;

    numPtrA = &numArr[2];    // �迭 �� ��° ����� �ּҸ� �����Ϳ� ����

    numPtrB = numPtrA;
    numPtrC = numPtrA;

    printf("%d\n", *(++numPtrB));    // 44: numPtrA���� ���������� 4����Ʈ��ŭ ������ 
                                     // �޸� �ּҿ� ����
    printf("%d\n", *(--numPtrC));    // 22: numPtrA���� ���������� 4����Ʈ��ŭ ������ 
                                     // �޸� �ּҿ� ����

    return 0;
}
