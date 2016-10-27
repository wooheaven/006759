#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fseek, rewind, fread, fclose �Լ��� ����� ��� ����
#include <string.h>    // strlen, memset �Լ��� ����� ��� ����

int main()
{
    char *s1 = "abcd";
    char buffer[20] = { 0, };

    FILE *fp = fopen("hello.txt", "r+");    // hello.txt ������ �б�/���� ���(r+)�� ����.
                                            // ���� �����͸� ��ȯ

    fseek(fp, 3, SEEK_SET);           // ���� �����͸� ���� ó������ 3����Ʈ��ŭ ���������� �̵���Ŵ
    fwrite(s1, strlen(s1), 1, fp);    // ���ڿ� ���̸�ŭ ���ڿ��� ���Ͽ� ����

    rewind(fp);                  // ���� �����͸� ������ �� ó������ �̵���Ŵ
    fread(buffer, 20, 1, fp);    // 20����Ʈ��ŭ ����

    printf("%s\n", buffer);      // Helabcdworld!

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
