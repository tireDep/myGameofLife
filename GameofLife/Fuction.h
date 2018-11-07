#pragma once
class LifeCell
{
public:
	LifeCell();
	~LifeCell();

	void SetSize();	// 격자 크기 설정 함수
	void SetField(); // 격자 설정 함수

	void LiveorDead();	// 생명 체크 함수
	void IsAlive(int *array[], int xGrid, int yGrid); // 생존여부 판별 함수
	void Display();	// 출력 함수
	void InputCell();	// 생명 입력 함수
	void Change();	// 변수 변환

	void Free();	// free 함

	void SetCell(int ygrid, int xgrid);	// 생명 위치 함수
	// 추가 함수 헤더

private:
	int size; // 격자 크기 변수
	int **nowField;	// 현재 세대
	int **nextField;	// 다음 세대
};