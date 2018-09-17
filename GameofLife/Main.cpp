#include "Basic.h"
#include "Fuction.h"

int main()
{
	int size; // 격자 크기 변수
	int i, j; // 반복문 변수
	
	printf("격자 크기를 입력하시오 >>");
	scanf_s("%d",&size);
	
	// int *field = (int *) malloc(sizeof(int)*size); 1차원 배열
	
	int **field = (int **)malloc(sizeof(int *)*size);
	for(i=0;i<size;i++)
		field[i] = (int *)malloc(sizeof(int)*size);	// *field로 하면 에러남
		// 2차원 배열 생성
	
	for(i=0;i<size;i++)
	{
		for (j = 0; j < size; j++)
			field[i][j] = 0;
	} // 초기화
// 격자생성

	int xgrid = 0, ygrid = 0; // 좌표값 변수, 실수로 1개만 입력했을 경우, 에러메시지를 띄우기 위해서 설정함

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
			printf("올바른 입력방법이 아닙니다.");
			xgrid = 0;
			ygrid = 0;	// 에러 방지를 위한 변수 초기화
			continue;
		}
		field[--ygrid][--xgrid] = 1;	// 배열 범위는 0~n-1, 입력은 편한 이해를 위해서 1~n으로 받기 때문

		xgrid = 0;
		ygrid = 0;	// 에러 방지를 위한 변수 초기화
	}

	puts("- 입력한 생명들 -");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",field[i][j]);
		}
		puts("");
	}
	// 생명 위치 입력&출력(후에 수정해보기)

	int inputCnt;	// 입력받을 세대수 변수
	printf("반복할 세대수를 입력하시오. >> ");
	scanf_s("%d", &inputCnt);	

	puts("12345678901238765464");
	for (i = 0; i < inputCnt; i++)	//	반복할 세대수 만큼 진행
	{
		LiveorDead(field);
	}
	puts("12345678901238765464");

	for (i = 0; i < size; i++)
		free(field[i]);
	free(field);
	// 메모리 해제
	
	printf("- 프로그램 종료 -\n\n");
	return 0;
}
