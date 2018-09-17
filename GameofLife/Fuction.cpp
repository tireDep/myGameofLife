#include "Basic.h"
#include "Fuction.h"

void LiveorDead(int *array[])
{
	int i, j;
	int checkArr = (_msize(array)) / (sizeof(array));	// ���� üũ ����, _misze() : malloc���� �Ҵ��� �޸� ũ�� ���� �� ����

	for (i = 0; i < checkArr; i++)
	{
		for (j = 0; j < checkArr; j++)
			IsAlive(array, j, i);
	}
}

void IsAlive(int *array[], int xGrid, int yGrid)
{
	/*
	-11 / 01 / 11
	-10 / 00 / 10
	-1-1 / 0-1 / 1-1

	���� �Ǵ� ��Ģ
	- 3�� : ����
	- 2�� : ��������
	- �׿� : ���
	=> ������ -1 �� �����ؾ��ҵ�? ==> �ڸ� �Ǻ��� ���ε� �Ǻ���
	*/

	int i, j;	// �ݺ��� ����
	int lifeCnt = 0; // ���� ��ó ���� ����

	for (i = yGrid - 1; i <= yGrid + 1; i++)
	{
		for (j = xGrid - 1; j <= xGrid + 1; j++)
		{
			if (array[i][j] == 1)
				lifeCnt++;
		}
	}

	// printf("!!!!�Լ� �����ʿ�");
}