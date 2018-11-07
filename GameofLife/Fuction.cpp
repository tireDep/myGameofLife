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
	} // 초기화
	  // 격자생성
}

void LifeCell::SetCell(int ygrid, int xgrid)
{
	nowField[--ygrid][--xgrid] = 1;	// 배열 범위는 0~n-1, 입력은 편한 이해를 위해서 1~n으로 받기 때문
}

void LifeCell::InputCell()
{
	int xgrid = 0, ygrid = 0; // 좌표값 변수, 실수로 1개만 입력했을 경우, 에러메시지를 띄우기 위해서 설정함
	while (1)
	{
		printf("생명의 위치를 입력하시오.(단, x,y형태로 입력할 것, 좌표값이 음수면 종료) >> ");
		scanf_s("%d,%d", &ygrid, &xgrid);
		if (xgrid<0 || ygrid<0)
		{
			printf("입력을 종료합니다.");
			puts("");
			break;
		}
		if (xgrid > size|| ygrid > size || xgrid == 0 || ygrid == 0)
		{
			printf("올바른 입력방법이 아닙니다.");
			xgrid = 0;
			ygrid = 0;	// 에러 방지를 위한 변수 초기화
			continue;
		}
		SetCell(ygrid, xgrid);
		xgrid = 0;
		ygrid = 0;	// 에러 방지를 위한 변수 초기화
	}
}


void LifeCell::LiveorDead()
{
	int i, j;
	int checkArr = (_msize(nowField)) / (sizeof(nowField));	// 범위 체크 변수, _misze() : malloc으로 할당한 메모리 크기 구할 수 있음

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

	생명 판단 규칙
	- 3개 : 생존
	- 2개 : 상태유지
	- 그외 : 사망
	=> 생명개수 -1 로 적용해야할듯? ==> 자리 판별시 본인도 판별됨
	*/

	int i, j;	// 반복문 변수
	int lifeCnt = 0; // 생명 근처 생명 개수
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
		// 추가할 내용 -> 현재 생명, 다음세대 생명도 함깨 판별해야 함!
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
				printf("■");
			else
				printf("□");
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
	// 메모리 해제
}