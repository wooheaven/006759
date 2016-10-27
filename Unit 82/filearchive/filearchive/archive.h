#ifndef ARCHIVE_H    // ARCHIVE_H�� ���ǵǾ� ���� �ʴٸ�
#define ARCHIVE_H    // ARCHIVE_H ��ũ������

#include <stdio.h>     // ���� ó�� �Լ��� ����� ��� ����
#include <stdint.h>    // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����
#include <stdbool.h>   // bool, true, false�� ���ǵ� ��� ����

#pragma pack(push, 1)    // ����ü�� 1����Ʈ ũ��� ����

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _ARCHIVE_HEADER {    // ��ī�̺� ��� ����ü ����
    uint16_t magic;                     // ��ī�̺� ���� ���� �ѹ�
    uint16_t version;                   // ��ī�̺� ���� ����
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

// ��ī�̺� ���Ͽ� ����Ǵ� ����ü
typedef struct _FILE_DESC {         // ���� ���� ����ü ����
    char     name[256];                 // ���� �̸�
    uint32_t size;                      // ���� ũ��
    uint32_t dataOffset;                // ���� �������� ��ġ
} FILE_DESC, *PFILE_DESC;

#pragma pack(pop)

// ���α׷������� ����ϴ� ����ü
typedef struct _FILE_NODE {         // ���� ��� ���� ����Ʈ ����ü ����
    struct _FILE_NODE *next;            // ���� ����� �ּҸ� ������ ������
    FILE_DESC desc;                     // ���� ����
} FILE_NODE, *PFILE_NODE;

// ���α׷������� ����ϴ� ����ü
typedef struct _ARCHIVE {           // ��ī�̺� ���� ����ü
    ARCHIVE_HEADER header;              // ��ī�̺� ���
    FILE *fp;                           // ��ī�̺� ���� ������
    FILE_NODE fileList;                 // ���� ��� ���� ����Ʈ�� �Ӹ� ���
} ARCHIVE, *PARCHIVE;

PARCHIVE initialize();                             // �ʱ�ȭ �Լ�
void finalize(PARCHIVE archive);                   // ���� �Լ�
bool isExist(PARCHIVE archive, char *filename);    // ��ī�̺꿡 Ư�� ������ �ִ��� �˻��ϴ� �Լ�

#endif               // #ifndef ARCHIVE_H ��
