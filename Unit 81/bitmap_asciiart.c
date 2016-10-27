#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>    // fopen, fread, fseek, fprintf, fclose �Լ��� ����� ��� ����
#include <stdlib.h>   // malloc, free �Լ��� ����� ��� ����

#pragma pack(push, 1)                // ����ü�� 1����Ʈ ũ��� ����

typedef struct _BITMAPFILEHEADER     // BMP ��Ʈ�� ���� ��� ����ü
{
    unsigned short bfType;           // BMP ���� ���� �ѹ�
    unsigned int   bfSize;           // ���� ũ��
    unsigned short bfReserved1;      // ����
    unsigned short bfReserved2;      // ����
    unsigned int   bfOffBits;        // ��Ʈ�� �������� ���� ��ġ
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP ��Ʈ�� ���� ��� ����ü(DIB ���)
{
    unsigned int   biSize;           // ���� ����ü�� ũ��
    int            biWidth;          // ��Ʈ�� �̹����� ���� ũ��
    int            biHeight;         // ��Ʈ�� �̹����� ���� ũ��
    unsigned short biPlanes;         // ����ϴ� �������� ��
    unsigned short biBitCount;       // �ȼ� �ϳ��� ǥ���ϴ� ��Ʈ ��
    unsigned int   biCompression;    // ���� ���
    unsigned int   biSizeImage;      // ��Ʈ�� �̹����� �ȼ� ������ ũ��
    int            biXPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    int            biYPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    unsigned int   biClrUsed;        // ���� ���̺��� ���� ���Ǵ� ���� ��
    unsigned int   biClrImportant;   // ��Ʈ���� ǥ���ϱ� ���� �ʿ��� ���� �ε��� ��
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE            // 24��Ʈ ��Ʈ�� �̹����� �ȼ� ����ü
{
    unsigned char rgbtBlue;          // �Ķ�
    unsigned char rgbtGreen;         // �ʷ�
    unsigned char rgbtRed;           // ����
} RGBTRIPLE;

#pragma pack(pop)

#define PIXEL_SIZE   3    // �ȼ� �� ���� ũ�� 3����Ʈ(24��Ʈ)
#define PIXEL_ALIGN  4    // �ȼ� ������ ���� �� ���� 4�� ��� ũ��� �����

int main()
{
    FILE *fpBmp;                    // ��Ʈ�� ���� ������
    FILE *fpTxt;                    // �ؽ�Ʈ ���� ������
    BITMAPFILEHEADER fileHeader;    // ��Ʈ�� ���� ��� ����ü ����
    BITMAPINFOHEADER infoHeader;    // ��Ʈ�� ���� ��� ����ü ����

    unsigned char *image;    // �ȼ� ������ ������
    int size;                // �ȼ� ������ ũ��
    int width, height;       // ��Ʈ�� �̹����� ����, ���� ũ��
    int padding;             // �ȼ� �������� ���� ũ�Ⱑ 4�� ����� �ƴ� �� ���� ������ ũ��

    // �� �ȼ��� ǥ���� ASCII ����. �ε����� ���� ���� ������� ���� ǥ��
    char ascii[] = { '#', '#', '@', '%', '=', '+', '*', ':', '-', '.', ' ' };   // 11��

    fpBmp = fopen("Lenna80x80.bmp", "rb");    // ��Ʈ�� ������ ���̳ʸ� ���� ����
    if (fpBmp == NULL)    // ���� ���⿡ �����ϸ�
        return 0;         // ���α׷� ����

    // ��Ʈ�� ���� ��� �б�. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
    if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1)
    {
        fclose(fpBmp);
        return 0;
    }

    // ���� �ѹ��� MB�� �´��� Ȯ��(2����Ʈ ũ���� BM�� ��Ʋ ��������� �о����Ƿ� MB�� ��)
    // ���� �ѹ��� ���� ������ ���α׷� ����
    if (fileHeader.bfType != 'MB')
    {
        fclose(fpBmp);
        return 0;
    }

    // ��Ʈ�� ���� ��� �б�. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
    if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1)
    {
        fclose(fpBmp);
        return 0;
    }

    // 24��Ʈ ��Ʈ���� �ƴϸ� ���α׷� ����
    if (infoHeader.biBitCount != 24)
    {
        fclose(fpBmp);
        return 0;
    }

    size = infoHeader.biSizeImage;    // �ȼ� ������ ũ��
    width = infoHeader.biWidth;       // ��Ʈ�� �̹����� ���� ũ��
    height = infoHeader.biHeight;     // ��Ʈ�� �̹����� ���� ũ��

    // �̹����� ���� ũ�⿡ �ȼ� ũ�⸦ ���Ͽ� ���� �� ���� ũ�⸦ ���ϰ� 4�� �������� ����
    // �׸��� 4���� �������� ���ָ� ���� ������ ���� �� ����.
    // ���� ���� ������ 0�̶�� ���� ����� 4�� �ǹǷ� ���⼭ �ٽ� 4�� �������� ����
    padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;

    if (size == 0)    // �ȼ� ������ ũ�Ⱑ 0�̶��
    {
        // �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ������ ���� �� �� ũ�Ⱑ ����
        // ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
        size = (width * PIXEL_SIZE + padding) * height;
    }

    image = malloc(size);    // �ȼ� �������� ũ�⸸ŭ ���� �޸� �Ҵ�

    // ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
    fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);

    // ���Ͽ��� �ȼ� ������ ũ�⸸ŭ ����. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
    if (fread(image, size, 1, fpBmp) < 1)
    {
        fclose(fpBmp);
        return 0;
    }

    fclose(fpBmp);    // ��Ʈ�� ���� �ݱ�

    fpTxt = fopen("ascii.txt", "w");    // ��� ��¿� �ؽ�Ʈ ���� ����
    if (fpTxt == NULL)    // ���� ���⿡ �����ϸ�
    {
        free(image);      // �ȼ� �����͸� ������ ���� �޸� ����
        return 0;         // ���α׷� ����
    }

    // �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�
    // ���� ũ�⸸ŭ �ݺ�
    for (int y = height - 1; y >= 0; y--)
    {
        // ���� ũ�⸸ŭ �ݺ�
        for (int x = 0; x < width; x++)
        {
            // �Ϸķ� �� �迭�� �����ϱ� ���� �ε����� ���
            // (x * �ȼ� ũ��)�� �ȼ��� ���� ��ġ
            // (y * (���� ũ�� * �ȼ� ũ��))�� �ȼ��� �� ��° ������ ���
            // ���� ���� * y�� �ٺ��� ������ ���� ����
            int index = (x * PIXEL_SIZE) + (y * (width * PIXEL_SIZE)) + (padding * y);

            // ���� �ȼ��� �ּҸ� RGBTRIPLE �����ͷ� ��ȯ�Ͽ� RGBTRIPLE �����Ϳ� ����
            RGBTRIPLE *pixel = (RGBTRIPLE *)&image[index];

            // RGBTRIPLE ����ü�� �Ķ�, �ʷ�, �������� ������
            unsigned char blue = pixel->rgbtBlue;
            unsigned char green = pixel->rgbtGreen;
            unsigned char red = pixel->rgbtRed;

            // �Ķ�, �ʷ�, �������� ����� ���ϸ� ��� �̹����� ���� �� ����
            unsigned char gray = (red + green + blue) / PIXEL_SIZE;

            // ��鰪�� ASCII ������ ������ ���� �� 256���� ������ ��鰪�� ���� 
            // ASCII ������ �ε����� ���� �� ����
            char c = ascii[gray * sizeof(ascii) / 256];

            // ��Ʈ�� �̹��������� �ȼ��� ����, ���� ũ�Ⱑ �Ȱ�����
            // ���� ASCII ���ڴ� ���η� ������ �����̹Ƿ� ���簢�� ���� ����ϰ� �����ֱ� ����
            // ���� ���ڸ� �� �� ��������
            fprintf(fpTxt, "%c%c", c, c);    // �ؽ�Ʈ ���Ͽ� ���� ���
        }

        fprintf(fpTxt, "\n");    // ���� �ȼ� ������ �������� �ٹٲ��� ����
    }

    fclose(fpTxt);    // �ؽ�Ʈ ���� �ݱ�

    free(image);      // �ȼ� �����͸� ������ ���� �޸� ����

    return 0;
}
