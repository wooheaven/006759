#include <stdio.h>

int main()
{
    printf("%c %d\n", 'a' + 1, 'a' + 1);    // b 98: a�� ASCII �ڵ尪 97�̰�, 
                                            // 97�� 1�� ���Ͽ� 98�� �Ǿ����Ƿ� b�� ��µ�

    printf("%c %d\n", 97 + 1, 97 + 1);      // b 98: ASCII �ڵ尪 97�� 1�� ���Ͽ� 98�� �Ǿ����Ƿ� 
                                            // b�� ��µ�

    return 0;
}
