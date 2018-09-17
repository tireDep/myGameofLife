#include "Basic.h"
#include "Fuction.h"

void LiveorDead(int *array[])
{
	int i, j;
	int checkArr = (_msize(array)) / (sizeof(array));	// 범위 체크 변수, _misze() : malloc으로 할당한 메모리 크기 구할 수 있음

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

	생명 판단 규칙
	- 3개 : 생존
	- 2개 : 상태유지
	- 그외 : 사망
	=> 생명개수 -1 로 적용해야할듯? ==> 자리 판별시 본인도 판별됨
	*/

	int i, j;	// 반복문 변수
	int lifeCnt = 0; // 생명 근처 생명 개수
	int checkArr = (_msize(array)) / (sizeof(array));

	for (i = yGrid - 1; i <= yGrid + 1; i++)
	{
		for (j = xGrid - 1; j <= xGrid + 1; j++)
		{
			if ((i>=0 && i<=checkArr) && (j >= 0 && j <= checkArr))
			{
				if (array[i][j] == 1)
					lifeCnt++;
			}
			else
				continue;
		}

		bool asdf = true;
	}

	// printf("!!!!함수 제작필요");
}