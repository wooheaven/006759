#include <stdio.h>

int main()
{
	unsigned char num1 = 200;                          // 1����Ʈ ��ȣ ���� ���������� 
	                                                   // ������ �����ϰ� �� �Ҵ�

	unsigned short num2 = 60000;                       // 2����Ʈ ��ȣ ���� ���������� 
	                                                   // ������ �����ϰ� �� �Ҵ�

	unsigned int num3 = 4123456789;                    // 4����Ʈ ��ȣ ���� ���������� 
	                                                   // ������ �����ϰ� �� �Ҵ�

	unsigned long num4 = 4123456789;                   // 4����Ʈ ��ȣ ���� ���������� 
	                                                   // ������ �����ϰ� �� �Ҵ�

	unsigned long long num5 = 12345678901234567890;    // 8����Ʈ ��ȣ ���� ���������� 
	                                                   // ������ �����ϰ� �� �Ҵ�

	// unsigned char, unsigned short, unsigned int�� %u�� ����ϰ� 
	// unsigned long�� %lu, unsigned long long�� %llu�� ���
	printf("%u %u %u %lu %llu\n", num1, num2, num3, num4, num5);
	// 200 60000 4123456789 4123456789 12345678901234567890

	return 0;
}
