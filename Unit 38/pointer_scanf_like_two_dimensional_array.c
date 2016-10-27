#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
    int row, col;

    scanf("%d %d", &row, &col);

    int **m = malloc(sizeof(int *) * row);   // ���� �����Ϳ� (int ������ ũ�� * row)��ŭ
                                             // ���� �޸� �Ҵ�. �迭�� ����

    for (int i = 0; i < row; i++)            // ���� ũ�⸸ŭ �ݺ�
    {
        m[i] = malloc(sizeof(int) * col);    // (int�� ũ�� * col)��ŭ ���� �޸� �Ҵ�. �迭�� ����
    }

    for (int i = 0; i < row; i++)    // ���� ũ�⸸ŭ �ݺ�
    {
        for (int j = 0; j < col; j++)    // ���� ũ�⸸ŭ �ݺ�
        {
            m[i][j] = i + j;             // 2���� �迭�� �� ��ҿ� i + j ���� �Ҵ�
        }
    }

    for (int i = 0; i < row; i++)    // ���� ũ�⸸ŭ �ݺ�
    {
        for (int j = 0; j < col; j++)    // ���� ũ�⸸ŭ �ݺ�
        {
            printf("%d ", m[i][j]);      // 2���� �迭�� �ε����� �ݺ����� ���� i, j�� ����
        }
        printf("\n");                // ���� ��Ҹ� ����� �� ���� �ٷ� �Ѿ
    }

    for (int i = 0; i < row; i++)    // ���� ũ�⸸ŭ �ݺ�
    {
        free(m[i]);                  // 2���� �迭�� ���� ���� �޸� ����
    }

    free(m);    // 2���� �迭�� ���� ���� �޸� ����

    return 0;
}
