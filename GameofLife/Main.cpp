#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

void LiveorDead(int *array[]);	// ���� üũ �Լ�
void IsAlive(int *array[], int lifeCnt); // �������� �Ǻ� �Լ�

int main()
{
	int size; // ���� ũ�� ����
	int i, j; // �ݺ��� ����
	
	printf("���� ũ�⸦ �Է��Ͻÿ� >>");
	scanf_s("%d",&size);
	
	// int *field = (int *) malloc(sizeof(int)*size);
	// 1���� �迭
	
	int **field = (int **)malloc(sizeof(int *)*size);
	for(i=0;i<size;i++)
	{
		field[i] = (int *)malloc(sizeof(int)*size);
		// *field�� �ϸ� ������
	}
	// 2���� �迭 ����
	
	for(i=0;i<size;i++)
	{
		for (j = 0; j < size; j++)
			field[i][j] = 0;
	} // �ʱ�ȭ
// ����ũ�� �Է±��� �Ϸ��!

	int xgrid = 0, ygrid = 0; // ��ǥ�� ����

	while(1)
	{
		printf("������ ��ġ�� �Է��Ͻÿ�.(��, x,y���·� �Է��� ��, ��ǥ���� ������ ����) >> ");
		scanf_s("%d,%d",&xgrid, &ygrid);
		if(xgrid<0 || ygrid<0)
		{
			printf("�Է��� �����մϴ�.");
			puts("");
			break;
		}
		if(xgrid>size || ygrid>size || xgrid ==0 || ygrid == 0)
		{
			printf("�ùٸ� �Է¹���� �ƴմϴ�.");
			xgrid = 0;
			ygrid = 0;	// ���� ������ ���� ���� �ʱ�ȭ
			continue;
		}
		field[--ygrid][--xgrid] = 1;	// �迭 ������ 0~4, �Է��� ���� ���ظ� ���ؼ� 1~5�� �ޱ� ����

		xgrid = 0;
		ygrid = 0;	// ���� ������ ���� ���� �ʱ�ȭ
	}
	// ���� ��ġ �Է¹���(�Ŀ� �����غ���)
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",field[i][j]);
		}
		puts("");
	}
	// test printf("%d\n\n\n", _msize(field));
	LiveorDead(field);
	puts("ok");
	
	return 0;
}
void LiveorDead(int *array[])
{
	int i,j;
	int lifeCnt=0; // ���� ��ó ���� ����
	int checkArr = _msize(array) / sizeof(array);	// ���� üũ ����, _misze() : malloc���� �Ҵ��� �޸� ũ�� ���� �� ����
	
	for(i=0;i<checkArr;i++)	
	{
		for(j=0;j<checkArr;j++)
		{
				if(array[i][j]==1)
					lifeCnt++;
		}
	}
	// IsAlive(array, lifeCnt);

}

void IsAlive(int *array[], int lifeCnt)
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

	// printf("%d ",lifeCnt);
	printf("!!!!�Լ� �����ʿ�");
}