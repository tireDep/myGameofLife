#include<stdio.h>
#include<stdlib.h>

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
	
/*	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",field[i][j]);
		}
		puts("");
	} // �ʱ�ȭ Ȯ�ο� */
// ����ũ�� �Է±��� �Ϸ��!
	int xgrid, ygrid; // ��ǥ�� ����
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
			printf("�ùٸ� ������ �ƴմϴ�");
			continue;
		}
		/*if(xgrid==size)
			xgrid--;
		else if(xgrid==1)
			xgrid++;
		if(ygrid==size)
			ygrid--;
		else if(ygrid==1)
			ygrid++;*/
		field[--ygrid][--xgrid] = 1;
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
	LiveorDead(field);
	puts("ok");
	
	return 0;
}
void LiveorDead(int *array[])
{
	/*
	-11 / 01 / 11
	-10 / 00 / 10
	-1-1 / 0-1 / 1-1
	*/
	int i,j;
	int lifeCnt=0; // ���� ��ó ���� ����
	for(i=0;i<sizeof(array)+1;i++)
	{
		for(j=0;j<sizeof(array)+1;j++)
		{
				/*
				���� �Ǵ� ��Ģ
				- 3�� : ����
				- 2�� : ��������
				- �׿� : ���
				=> ������ -1 �� �����ؾ��ҵ�? ==> �ڸ� �Ǻ��� ���ε� �Ǻ���
				*/
				if(array[i][j]==1)
					lifeCnt++;
		}
		if(i==sizeof(array)-1)
			IsAlive(array, lifeCnt);
	}
	printf("�Լ� �����ʿ�");
}
void IsAlive(int *array[], int lifeCnt)
{
	printf("%d ",lifeCnt);
	printf("�Լ� �����ʿ�");
}