#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[30];               // �ܾ ������ �迭
    int length;                  // ���ڿ� ����
    bool isPalindrome = true;    // ȸ�� �Ǻ����� ������ ����, �ʱ갪�� true

    printf("�ܾ �Է��ϼ���: ");
    scanf("%s", word);

    length = strlen(word);    // ���ڿ��� ���̸� ����
    
    // 0���� ���ڿ� ������ ���ݸ�ŭ �ݺ�
    for (int i = 0; i < length / 2; i++)
    {
        // ���� ���ڿ� ������ ���ڸ� ���Ͽ� ���ڰ� �ٸ���
        if (word[i] != word[length - 1 - i])
        {
            // ȸ���� �ƴ�
            isPalindrome = false;
            break;
        }
    }

    printf("%d\n", isPalindrome);    // ȸ�� �Ǻ��� ���

    return 0;
}
