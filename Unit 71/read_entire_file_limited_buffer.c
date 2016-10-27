#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, feof, fread, fclose �Լ��� ����� ��� ����
#include <string.h>    // strlen, memset �Լ��� ����� ��� ����

int main()
{
    char buffer[5] = { 0, };    // ���ڿ� ������ 4����Ʈ NULL 1����Ʈ. 4 + 1 = 5
    int count = 0;
    int total = 0;

    FILE *fp = fopen("hello.txt", "r");    // hello.txt ������ �б� ���(r)�� ����.
                                           // ���� �����͸� ��ȯ

    while (feof(fp) == 0)    // ���� �����Ͱ� ������ ���� �ƴ� �� ��� �ݺ�
    {
        count = fread(buffer, sizeof(char), 4, fp);    // 1����Ʈ�� 4��(4����Ʈ) �б�
        printf("%s", buffer);                          // ���� ���� ���
        memset(buffer, 0, 5);                          // ���۸� 0���� �ʱ�ȭ
        total += count;                                // ���� ũ�� ����
    }

    printf("\ntotal: %d\n", total);    // total: 13: ������ ���� ��ü ũ�� ���

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
