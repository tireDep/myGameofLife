#include "Basic.h"
#include "Fuction.h"

int main()
{
	int size; // ���� ũ�� ����
	int i, j; // �ݺ��� ����
	
	printf("���� ũ�⸦ �Է��Ͻÿ� >>");
	scanf_s("%d",&size);
	
	// int *field = (int *) malloc(sizeof(int)*size); 1���� �迭
	
	int **field = (int **)malloc(sizeof(int *)*size);
	for(i=0;i<size;i++)
		field[i] = (int *)malloc(sizeof(int)*size);	// *field�� �ϸ� ������
		// 2���� �迭 ����
	
	for(i=0;i<size;i++)
	{
		for (j = 0; j < size; j++)
			field[i][j] = 0;
	} // �ʱ�ȭ
// ���ڻ���

	int xgrid = 0, ygrid = 0; // ��ǥ�� ����, �Ǽ��� 1���� �Է����� ���, �����޽����� ���� ���ؼ� ������

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
		field[--ygrid][--xgrid] = 1;	// �迭 ������ 0~n-1, �Է��� ���� ���ظ� ���ؼ� 1~n���� �ޱ� ����

		xgrid = 0;
		ygrid = 0;	// ���� ������ ���� ���� �ʱ�ȭ
	}

	puts("- �Է��� ����� -");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",field[i][j]);
		}
		puts("");
	}
	// ���� ��ġ �Է�&���(�Ŀ� �����غ���)

	int inputCnt;	// �Է¹��� ����� ����
	printf("�ݺ��� ������� �Է��Ͻÿ�. >> ");
	scanf_s("%d", &inputCnt);	

	puts("12345678901238765464");
	for (i = 0; i < inputCnt; i++)	//	�ݺ��� ����� ��ŭ ����
	{
		LiveorDead(field);
	}
	puts("12345678901238765464");

	for (i = 0; i < size; i++)
		free(field[i]);
	free(field);
	// �޸� ����
	
	printf("- ���α׷� ���� -\n\n");
	return 0;
}
