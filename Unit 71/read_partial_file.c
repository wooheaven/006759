#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fseek, fread, fclose �Լ��� ����� ��� ����
#include <string.h>    // memset �Լ��� ����� ��� ����

int main()
{
    char buffer[10] = { 0, };

    FILE *fp = fopen("hello.txt", "r");    // hello.txt ������ �б� ���(r)�� ����.
                                           // ���� �����͸� ��ȯ

    fseek(fp, 2, SEEK_SET);     // ���� �����͸� ���� ó������ 2����Ʈ��ŭ ���������� �̵���Ŵ
    fread(buffer, 3, 1, fp);    // 3����Ʈ��ŭ ����. 3����Ʈ��ŭ ���������� �̵�

    printf("%s\n", buffer);     // llo

    memset(buffer, 0, 10);      // ���۸� 0���� �ʱ�ȭ

    fseek(fp, 3, SEEK_CUR);     // ���� �����͸� ���� ��ġ���� 3����Ʈ��ŭ ���������� �̵���Ŵ
    fread(buffer, 4, 1, fp);    // 4����Ʈ��ŭ ����. 4����Ʈ��ŭ ���������� �̵�

    printf("%s\n", buffer);     // orld

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
