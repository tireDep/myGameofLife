#include "Basic.h"
#include "Fuction.h"

int main()
{
	LifeCell lifeCell;	// ���� ����
	
	printf("���� ũ�⸦ �Է��Ͻÿ� >>");
	lifeCell.SetSize();	// ���� ũ��
	lifeCell.SetField();	// ���� ����
	lifeCell.InputCell();	// ���� �Է� ����

	puts("- �Է��� ����� -");
	lifeCell.Display();

	int inputCnt;	// �Է¹��� ����� ����
	printf("\n�ݺ��� ������� �Է��Ͻÿ�. >> ");
	scanf_s("%d", &inputCnt);	

	for (int i = 0; i < inputCnt + 1; i++)	//	�ݺ��� ����� ��ŭ ���� -> 0������� �����ϱ� ������ +1
	{
		system("cls");	// ȭ�� ����
		printf("- %d���� -\n", i);
		lifeCell.LiveorDead();
		lifeCell.Display();
		puts("");
		Sleep(1000);

		if(inputCnt!=i)	// �� ������ ���뿡���� ���� ��ȯ�� �ʿ� x
			lifeCell.Change();
	}

	system("cls");	// ȭ�� ����
	puts("\n- ���� ��� -");
	lifeCell.Display();
	// n���� ���� �� Ȯ�ο� ���
	lifeCell.Free();
	printf("\n���α׷� ���� \n\n");
	return 0;
}
