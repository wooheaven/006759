#ifndef COMMAND_H    // COMMAND_H�� ���ǵǾ� ���� �ʴٸ�
#define COMMAND_H    // COMMAND_H ��ũ������

#include "archive.h"

int append(PARCHIVE archive, char *filename);     // ���� �߰� �Լ�
void list(PARCHIVE archive);                      // ���� ��� ��� �Լ�
int extract(PARCHIVE archive, char *filename);    // ���� ���� �Լ�

#endif               // #ifndef COMMAND_H ��
