#include <stdio.h>

int main()
{
    float num1 = 0.0f;
    float num2 = 0.1f;

    // 0.1�� 10�� ����
    for (int i = 0; i < 10; i++)
    {
        num1 = num1 + num2;
    }

    // num1: 0.100000001490116
    if (num1 == 1.0f)         // �ݿø� ������ �߻��ϹǷ� �Ǽ��� ==�� ���ϸ� �ȵ�
        printf("true\n");
    else
        printf("false\n");    // num1�� 1.0�� �ƴϹǷ� false ���

    return 0;
}
