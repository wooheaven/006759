#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct NODE {    // ���� ����Ʈ�� ��� ����ü
    struct NODE *next;    // ���� ����� �ּҸ� ������ ������
    int data;             // �����͸� ������ ���
};

void addFirst(struct NODE *target, int data)    // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
    struct NODE *newNode = malloc(sizeof(struct NODE));    // �� ��� ����
    newNode->next = target->next;    // �� ����� ���� ��忡 ���� ����� ���� ��带 ����
    newNode->data = data;            // ������ ����

    target->next = newNode;    // ���� ����� ���� ��忡 �� ��带 ����
}

void removeFirst(struct NODE *target)    // ���� ����� ���� ��带 �����ϴ� �Լ�
{
    struct NODE *removeNode = target->next;    // ���� ����� ���� ��� �ּҸ� ����
    target->next = removeNode->next;     // ���� ����� ���� ��忡 ������ ����� ���� ��带 ����

    free(removeNode);    // ��� �޸� ����
}

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE));    // �Ӹ� ��� ����
                                                        // �Ӹ� ���� �����͸� �������� ����
    head->next = NULL;

    addFirst(head, 10);    // �Ӹ� ��� �ڿ� �� ��� �߰�
    addFirst(head, 20);    // �Ӹ� ��� �ڿ� �� ��� �߰�
    addFirst(head, 30);    // �Ӹ� ��� �ڿ� �� ��� �߰�

    removeFirst(head);     // �Ӹ� ��� �ڿ� �ִ� ��带 ����

    struct NODE *curr = head->next;    // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
    while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
    {
        printf("%d\n", curr->data);    // ���� ����� ������ ���
        curr = curr->next;             // �����Ϳ� ���� ����� �ּ� ����
    }

    curr = head->next;      // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
    while (curr != NULL)    // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
    {
        struct NODE *next = curr->next;    // ���� ����� ���� ��� �ּҸ� �ӽ÷� ����
        free(curr);                        // ���� ��� �޸� ����
        curr = next;                       // �����Ϳ� ���� ����� �ּ� ����
    }

    free(head);    // �Ӹ� ��� �޸� ����

    return 0;
}
