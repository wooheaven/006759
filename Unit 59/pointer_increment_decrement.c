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

    numPtrB++;    // ������ ����
    numPtrC--;    // ������ ����

    printf("%p\n", numPtrA);    // 00A3FC08: �޸� �ּ�. ��ǻ�͸���, ������ ������ �޶���
    printf("%p\n", numPtrB);    // 00A3FC0C: sizeof(int) * 1�̹Ƿ� numPtrA���� 4�� ������
    printf("%p\n", numPtrC);    // 00A3FC04: sizeof(int) * -1�̹Ƿ� numPtrB���� 4�� ������

    return 0;
}
