#pragma once
class LifeCell
{
public:
	LifeCell();
	~LifeCell();

	void SetSize();	// ���� ũ�� ���� �Լ�
	void SetField(); // ���� ���� �Լ�

	void LiveorDead();	// ���� üũ �Լ�
	void IsAlive(int *array[], int xGrid, int yGrid); // �������� �Ǻ� �Լ�
	void Display();	// ��� �Լ�
	void InputCell();	// ���� �Է� �Լ�
	void Change();	// ���� ��ȯ

	void Free();	// free ��

	void SetCell(int ygrid, int xgrid);	// ���� ��ġ �Լ�
	// �߰� �Լ� ���

private:
	int size; // ���� ũ�� ����
	int **nowField;	// ���� ����
	int **nextField;	// ���� ����
};