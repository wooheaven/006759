#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>    // fopen, fread, fclose �Լ��� ����� ��� ����

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

    FILE *fp = fopen("data2.bin", "rb");   // ������ �б�/���̳ʸ� ���(rb)�� ����

    fread(&d1, sizeof(d1), 1, fp);         // ������ ������ �о ����ü ������ ����

    printf("%c %d %d %s\n", d1.c1, d1.num1, d1.num2, d1.s1);    // a 32100 2100000100 Hello, world!

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
