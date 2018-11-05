#include "Basic.h"
#include "Fuction.h"

void LiveorDead(int *array[])
{
	int i, j;
	int checkArr = (_msize(array)) / (sizeof(array));	// ���� üũ ����, _misze() : malloc���� �Ҵ��� �޸� ũ�� ���� �� ����

	for (i = 0; i < checkArr; i++)
	{
		for (j = 0; j < checkArr; j++)
		{
			IsAlive(array, j, i);
		}
	}
}

void IsAlive(int *array[], int xGrid, int yGrid)
{
	/*
	-11 / 01 / 11
	-10 / 00 / 10
	-1-1 / 0-1 / 1-1

	00/10/20
	01/11/21
	02/12/22

	���� �Ǵ� ��Ģ
	- 3�� : ����
	- 2�� : ��������
	- �׿� : ���
	=> ������ -1 �� �����ؾ��ҵ�? ==> �ڸ� �Ǻ��� ���ε� �Ǻ���
	*/

	int i, j;	// �ݺ��� ����
	int lifeCnt = 0; // ���� ��ó ���� ����
	int checkArr = (_msize(array)) / (sizeof(array));

	for (i = yGrid - 1; i <= yGrid + 1; i++)
	{
		for (j = xGrid - 1; j <= xGrid + 1; j++)
		{
			if ((i>=0 && i<checkArr) && (j >= 0 && j <checkArr))
			{
				if (array[i][j] == 1)
					lifeCnt++;
			}
			else
				continue;
		}
	}

	// LIfeCheck();
	{
		if (lifeCnt -1 >= 2)
			array[yGrid][xGrid] = 1;
		else
			array[yGrid][xGrid] = 0;
		lifeCnt = 0;
	}

}

void Display(int *array[])
{
	int checkArr = (_msize(array)) / (sizeof(array));

	for (int y = 0; y < checkArr; y++)
	{
		for (int x = 0; x < checkArr; x++)
		{
			// printf("%d ", field[i][j]);
			if (array[y][x] == 1)
				printf("��");
			else
				printf("��");
		}
		puts("");
	}
}