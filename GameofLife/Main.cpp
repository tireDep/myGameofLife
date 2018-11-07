#include "Basic.h"
#include "Fuction.h"

int main()
{
	LifeCell lifeCell;	// 변수 선언
	
	printf("격자 크기를 입력하시오 >>");
	lifeCell.SetSize();	// 격자 크기
	lifeCell.SetField();	// 격자 설정
	lifeCell.InputCell();	// 생명 입력 받음

	puts("- 입력한 생명들 -");
	lifeCell.Display();

	int inputCnt;	// 입력받을 세대수 변수
	printf("\n반복할 세대수를 입력하시오. >> ");
	scanf_s("%d", &inputCnt);	

	for (int i = 0; i < inputCnt + 1; i++)	//	반복할 세대수 만큼 진행 -> 0세대부터 시작하기 때문에 +1
	{
		system("cls");	// 화면 삭제
		printf("- %d세대 -\n", i);
		lifeCell.LiveorDead();
		lifeCell.Display();
		puts("");
		Sleep(1000);

		if(inputCnt!=i)	// 맨 마지막 세대에서는 값을 변환할 필요 x
			lifeCell.Change();
	}

	system("cls");	// 화면 삭제
	puts("\n- 최종 결과 -");
	lifeCell.Display();
	// n세대 지난 후 확인용 출력
	lifeCell.Free();
	printf("\n프로그램 종료 \n\n");
	return 0;
}
