#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>    // fopen, fwrite, fclose �Լ��� ����� ��� ����

#pragma pack(push, 1)    // 1����Ʈ ũ��� ����
struct Data {
    short num1;    // 2����Ʈ
    short num2;    // 2����Ʈ
    short num3;    // 2����Ʈ
    short num4;    // 2����Ʈ
};
#pragma pack(pop)        // ���� ������ ���� ����(�⺻��)�� �ǵ���

int main()
{
    struct Data d1;

    d1.num1 = 100;
    d1.num2 = 200;
    d1.num3 = 300;
    d1.num4 = 400;

    FILE *fp = fopen("data.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����

    fwrite(&d1, sizeof(d1), 1, fp);       // ����ü�� ������ ���Ͽ� ����

    fclose(fp);    // ���� ������ �ݱ�

    return 0;
}
