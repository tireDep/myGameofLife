#include "Basic.h"
#include "Fuction.h"

LifeCell::LifeCell()
{
}

LifeCell::~LifeCell()
{
}

void LifeCell::SetSize()
{
	scanf_s("%d", &this->size);
}

void LifeCell::SetField()
{
	this->nowField = (int **)malloc(sizeof(int *)*size);
	this->nextField = (int **)malloc(sizeof(int *)*size);

	for (int i = 0; i < size; i++)
	{
		nowField[i] = (int *)malloc(sizeof(int)*size);
		nextField[i] = (int *)malloc(sizeof(int)*size);
	}

	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			nowField[i][j] = 0;
			nextField[i][j] = 0;
		}
	} // �ʱ�ȭ
	  // ���ڻ���
}

void LifeCell::SetCell(int ygrid, int xgrid)
{
	nowField[--ygrid][--xgrid] = 1;	// �迭 ������ 0~n-1, �Է��� ���� ���ظ� ���ؼ� 1~n���� �ޱ� ����
}

void LifeCell::InputCell()
{
	int xgrid = 0, ygrid = 0; // ��ǥ�� ����, �Ǽ��� 1���� �Է����� ���, �����޽����� ���� ���ؼ� ������
	while (1)
	{
		printf("������ ��ġ�� �Է��Ͻÿ�.(��, x,y���·� �Է��� ��, ��ǥ���� ������ ����) >> ");
		scanf_s("%d,%d", &ygrid, &xgrid);
		if (xgrid<0 || ygrid<0)
		{
			printf("�Է��� �����մϴ�.");
			puts("");
			break;
		}
		if (xgrid > size|| ygrid > size || xgrid == 0 || ygrid == 0)
		{
			printf("�ùٸ� �Է¹���� �ƴմϴ�.");
			xgrid = 0;
			ygrid = 0;	// ���� ������ ���� ���� �ʱ�ȭ
			continue;
		}
		SetCell(ygrid, xgrid);
		xgrid = 0;
		ygrid = 0;	// ���� ������ ���� ���� �ʱ�ȭ
	}
}


void LifeCell::LiveorDead()
{
	int i, j;
	int checkArr = (_msize(nowField)) / (sizeof(nowField));	// ���� üũ ����, _misze() : malloc���� �Ҵ��� �޸� ũ�� ���� �� ����

	for (i = 0; i < checkArr; i++)
	{
		for (j = 0; j < checkArr; j++)
			IsAlive(nowField, j, i);
	}
}

void LifeCell::Change()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j<size; j++)
			nowField[i][j] = nextField[i][j];
	}
}

void LifeCell::IsAlive(int *nowField[], int xGrid, int yGrid)
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
	int checkArr = (_msize(nowField)) / (sizeof(nowField));

	for (i = yGrid - 1; i <= yGrid + 1; i++)
	{
		for (j = xGrid - 1; j <= xGrid + 1; j++)
		{
			if ((i >= 0 && i<checkArr) && (j >= 0 && j <checkArr))
			{
				if (nowField[i][j] == 1)
					lifeCnt++;
			}
			else
				continue;
		}
	}

	// LIfeCheck();
	{
		// �߰��� ���� -> ���� ����, �������� ���� �Ա� �Ǻ��ؾ� ��!
		if ((lifeCnt - 1 >= 2 && lifeCnt - 1 <= 3))
			nextField[yGrid][xGrid] = 1;
		else
			nextField[yGrid][xGrid] = 0;
		lifeCnt = 0;
	}
}

void LifeCell::Display()
{
	int checkArr = (_msize(nowField)) / (sizeof(nowField));

	for (int y = 0; y < checkArr; y++)
	{
		for (int x = 0; x < checkArr; x++)
		{
			// printf("%d ", field[i][j]);
			if (nowField[y][x] == 1)
				printf("��");
			else
				printf("��");
		}
		puts("");
	}
}

void  LifeCell::Free()
{
	for (int i = 0; i < size; i++)
		free(nowField[i]);
	free(nowField);

	for (int i = 0; i < size; i++)
		free(nextField[i]);
	free(nextField);
	// �޸� ����
}