#include <stdio.h>

void print2DArray(int (*arr)[5], int col, int row)   // �Ű������� �����ͷ� ���� �� ���� ũ�� ����
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int numArr[2][5] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 }
    };

    int col = sizeof(numArr[0]) / sizeof(int);       // 5: 2���� �迭�� ���� ũ�⸦ ���� ���� 
                                                     // ���� �� ���� ����� ũ��� ������

    int row = sizeof(numArr) / sizeof(numArr[0]);    // 2: 2���� �迭�� ���� ũ�⸦ ���� ���� 
                                       // �迭�� �����ϴ� ������ ���� �� ���� ũ��� ������

    print2DArray(numArr, col, row);    // 2���� �迭�� ����, ���� ũ�⸦ ����

    return 0;
}
