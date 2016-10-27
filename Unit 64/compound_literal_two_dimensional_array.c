#include <stdio.h>

void print2DArray(int (*arr)[5], int col, int row)
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
    // ���� ���ͷ� ������� 2���� �迭�� �Ѱ���
    print2DArray((int[2][5]) { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 } }, 5, 2);

    return 0;
}
