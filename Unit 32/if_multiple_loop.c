#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num1 = 0;

    bool exitOuterLoop = false;    // �ٱ��� ������ ���������� �����ϴ� ����
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (num1 == 20)              // num1�� 20�̶��
            {
                exitOuterLoop = true;    // �ٱ��� ������ ������������
                break;                   // ���� ������ ����
            }

            num1++;
        }

        if (exitOuterLoop == true)    // �ٱ��� ������ ���������ڴٰ� ����������
            break;                    // �ٱ��� ������ ����
    }

    printf("%d\n", num1);    // 20

    return 0;
}
