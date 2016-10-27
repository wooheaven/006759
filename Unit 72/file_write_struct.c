#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fwrite, fclose �Լ��� ����� ��� ����
#include <string.h>    // strcpy, memset �Լ��� ����� ��� ����

#pragma pack(push, 1)    // 1����Ʈ ũ��� ����
struct Data {
    char c1;        // 1����Ʈ
    short num1;     // 2����Ʈ
    int num2;       // 4����Ʈ
    char s1[20];    // 20����Ʈ
};
#pragma pack(pop)        // ���� ������ ���� ����(�⺻��)�� �ǵ���

int main()
{
    struct Data d1;
    memset(&d1, 0, sizeof(d1));    // ����ü ������ ������ 0���� �ʱ�ȭ

    d1.c1 = 'a';                       // ���� ����
    d1.num1 = 32100;                   // 2����Ʈ ũ���� ���� ����
    d1.num2 = 2100000100;              // 4����Ʈ ũ���� ���� ����
    strcpy(d1.s1, "Hello, world!");    // ���ڿ� ����

    FILE *fp = fopen("data2.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����

    fwrite(&d1, sizeof(d1), 1, fp);        // ����ü�� ������ ���Ͽ� ����

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
