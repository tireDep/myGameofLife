#include<stdio.h>
#include<stdlib.h>

void LiveorDead(int *array[]);	// 생명 체크 함수
void IsAlive(int *array[], int lifeCnt); // 생존여부 판별 함수

int main()
{
	int size; // 격자 크기 변수
	int i, j; // 반복문 변수
	
	printf("격자 크기를 입력하시오 >>");
	scanf_s("%d",&size);
	
	// int *field = (int *) malloc(sizeof(int)*size);
	// 1차원 배열
	
	int **field = (int **)malloc(sizeof(int *)*size);
	for(i=0;i<size;i++)
	{
		field[i] = (int *)malloc(sizeof(int)*size);
		// *field로 하면 에러남
	}
	// 2차원 배열 생성
	
/*	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",field[i][j]);
		}
		puts("");
	} // 초기화 확인용 */
// 격자크기 입력까지 완료됨!
	int xgrid, ygrid; // 좌표값 변수
	while(1)
	{
		printf("생명의 위치를 입력하시오.(단, x,y형태로 입력할 것, 좌표값이 음수면 종료) >> ");
		scanf_s("%d,%d",&xgrid, &ygrid);
		if(xgrid<0 || ygrid<0)
		{
			printf("입력을 종료합니다.");
			puts("");
			break;
		}
		if(xgrid>size || ygrid>size || xgrid ==0 || ygrid == 0)
		{
			printf("올바른 범위가 아닙니다");
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
	// 생명 위치 입력받음(후에 수정해보기)
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
	int lifeCnt=0; // 생명 근처 생명 개수
	for(i=0;i<sizeof(array)+1;i++)
	{
		for(j=0;j<sizeof(array)+1;j++)
		{
				/*
				생명 판단 규칙
				- 3개 : 생존
				- 2개 : 상태유지
				- 그외 : 사망
				=> 생명개수 -1 로 적용해야할듯? ==> 자리 판별시 본인도 판별됨
				*/
				if(array[i][j]==1)
					lifeCnt++;
		}
		if(i==sizeof(array)-1)
			IsAlive(array, lifeCnt);
	}
	printf("함수 제작필요");
}
void IsAlive(int *array[], int lifeCnt)
{
	printf("%d ",lifeCnt);
	printf("함수 제작필요");
}