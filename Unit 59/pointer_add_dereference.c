#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int *numPtrA;

    numPtrA = numArr;    // �迭 ù ��° ����� �ּҸ� �����Ϳ� ����

    printf("%d\n", *(numPtrA + 1));    // 22: numPtrA���� ���������� 4����Ʈ��ŭ ������ 
                                       // �޸� �ּҿ� ����. numArr[1]�� ����

    printf("%d\n", *(numPtrA + 2));    // 33: numPtrA���� ���������� 8����Ʈ��ŭ ������ 
                                       // �޸� �ּҿ� ����. numArr[2]�� ����

    return 0;
}
