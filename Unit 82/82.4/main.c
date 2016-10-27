#define _CRT_SECURE_NO_WARNINGS    // fopen, strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdint.h>    // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <string.h>    // strcpy, memset �Լ��� ����� ��� ����

#pragma pack(push, 1)    // ����ü�� 1����Ʈ ũ��� ����

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _ARCHIVE_HEADER {   // ��ī�̺� ��� ����ü ����
    uint16_t magic;                    // ��ī�̺� ���� ���� �ѹ�
    uint16_t version;                  // ��ī�̺� ���� ����
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _FILE_DESC {        // ���� ���� ����ü ����
    char     name[256];                // ���� �̸�
    uint32_t size;                     // ���� ũ��
    uint32_t dataOffset;               // ���� �������� ��ġ
} FILE_DESC, *PFILE_DESC;

#pragma pack(pop)

// ���α׷������� ����ϴ� ����ü
typedef struct _ARCHIVE {          // ��ī�̺� ���� ����ü
    ARCHIVE_HEADER header;             // ��ī�̺� ���
    FILE *fp;                          // ��ī�̺� ���� ������
} ARCHIVE, *PARCHIVE;

#define ARCHIVE_NAME "archive.bin"   // ��ī�̺� ���� �̸�

uint32_t getFileSize(FILE *fp)    // ������ ũ�⸦ ���ϴ� �Լ� ����
{
    uint32_t size;
    uint32_t currPos = ftell(fp);    // ���� ���� �������� ��ġ ����

    // ������ ������ �̵��Ͽ� ���� ũ�⸦ ����
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fseek(fp, currPos, SEEK_SET);    // ���� �������� ���� ��ġ�� �ǵ���

    return size;
}

int append(PARCHIVE archive, char *filename)    // ���� �߰� �Լ� ����
{
    int ret = 0;    // �Լ��� �����ߴ��� �����ߴ��� ��ȯ������ ǥ��

    // �߰��� ���� ����
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("%s ������ �����ϴ�.\n", filename);
        return -1;    // �Լ� ����. -1�� ����
    }

    uint8_t *buffer;
    uint32_t size;

    size = getFileSize(fp);    // �߰��� ������ ũ�⸦ ����
    buffer = malloc(size);

    // �߰��� ������ ������ ����
    if (fread(buffer, size, 1, fp) < 1)
    {
        printf("%s ���� �б� ����\n", filename);
        ret = -1;       // -1�� ����
        goto Error1;    // fp�� �ݰ� buffer�� �����ϴ� ���� ó���� �̵�
    }

    // �� ���� ���� ����
    PFILE_DESC desc = malloc(sizeof(FILE_DESC));
    memset(desc, 0, sizeof(FILE_DESC));
    strcpy(desc->name, filename);    // ���� ���� ����ü�� �߰��� ������ �̸� ����
    desc->size = size;               // ���� ���� ����ü�� �߰��� ������ ũ�� ����

    // ��ī�̺� ��� �ٷ� �������� ���� �����͸� �̵���Ŵ
    fseek(archive->fp, sizeof(ARCHIVE_HEADER), SEEK_SET);

    // ���� �������� ���� ��ġ�� ���� ���� �������� ��ġ�� 
    // ���� ���� ũ�⸸ŭ ���������� �̵���Ų ��
    desc->dataOffset = ftell(archive->fp) + sizeof(FILE_DESC);

    // ��ī�̺� ���Ͽ� �� ���� ���� ����
    if (fwrite(desc, sizeof(FILE_DESC), 1, archive->fp) < 1)
    {
        printf("���� ���� ���� ����\n");
        ret = -1;
        goto Error2;    // fp�� �ݰ�, desc�� buffer�� �����ϴ� ���� ó���� �̵�
    }

    // ��ī�̺� ���Ͽ� �� ���� ������ ����
    if (fwrite(buffer, size, 1, archive->fp) < 1)
    {
        printf("���� ������ ���� ����\n");
        ret = -1;
        goto Error2;    // fp�� �ݰ�, desc�� buffer�� �����ϴ� ���� ó���� �̵�
    }

    printf("%s ���� �߰� ����\nũ��: %d\n", filename, size);

Error2:
    free(desc);      // ���� ���� ����� ���� �޸� ����

Error1:
    free(buffer);    // ���� ���� ����� ���� �޸� ����

    fclose(fp);      // ���� ������ �ݱ�

    return ret;      // �����̳� ���гĿ� ���� 0 �Ǵ� -1�� ��ȯ
}

int main()
{
    PARCHIVE archive = malloc(sizeof(ARCHIVE));
    memset(archive, 0, sizeof(ARCHIVE));

    FILE *fp = fopen(ARCHIVE_NAME, "r+b");   // ��ī�̺� ������ �б�/���� ���� ����
    if (fp == NULL)                          // ��ī�̺� ������ ������
    {
        fp = fopen(ARCHIVE_NAME, "w+b");     // ��ī�̺� ������ ����
        if (fp == NULL)                      // ���� ����(����)�� �����ϸ�
            return -1;                       // ���α׷� ���� 

        // �� ��ī�̺� ��� ����
        archive->header.magic = 'AF';        // ���� �ѹ� AF ����(��Ʋ ����𿡼��� FA�� �����)
        archive->header.version = 1;         // ���� ���� 1 ����

        // ��ī�̺� ���Ͽ� ��ī�̺� ��� ����
        if (fwrite(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
        {
            printf("��ī�̺� ��� ���� ����\n");
            fclose(fp);
            return -1;
        }

        archive->fp = fp;    // ��ī�̺� ���� ������ ����

        append(archive, "hello.txt");    // hello.txt ���� �߰�
    }

    fclose(fp);    // ��ī�̺� ���� ������ �ݱ�

    free(archive);    // ���� �޸� ����

    return 0;
}
