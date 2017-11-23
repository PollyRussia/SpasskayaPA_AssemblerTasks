// Task 4.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// ������� ������ ������� � ���������� �����
void print(const char* arr1)
{
	//cout << "\n";
	int i = strlen(arr1) - 1;
	while (arr1[i] <= '0' && i > 0)
		i--;
	for (i = i; i >= 0; i--)
		cout << arr1[i];
	cout << "\n";
}

int main()
{
	// ����������
	string s1, s2;
	// ����������� 11 ��������, � ���-�� 10 ������ ��� ��� ���������� ������� 0, � �� 48, ���� ���� �������� "0" 
	// ������� ���  arr1[10] ��������� �������� ��������� ���������� ������� � "0", � ��� �� ������ �� ����������
	char arr1[11] = "0000000000"; // ������ ��� 1 �����
	char arr2[11] = "0000000000"; // ������ ��� 2 �����
	char arr3[12] = "00000000000"; // ��������� ��������
	char arr4[12] = "00000000000"; //��������� ���������
	int result = 1; // ��������� ���������
	const char* arr0; // ��������������� ������ ��� �������������� ������ � ������������ ������

	setlocale(LC_ALL, "RUS"); // ����� ������� ������� ����������
	cout << "������ 4, 5, 6" << "\n";
	cout << "������������ ������ ��� ����� � �������� �� �����, �������� � ��������� ���������" << "\n";
	cout << "�������� �����������, ������ ���� ������ ����� �� ������ �������" << "\n";
	
	// ����
	cout << "������� ������ ����� (�� 10 ��������)" << "\n";
	getline(cin, s1); // ������ 1-�� ����� (������)
	arr0 = s1.data();
	for (int i = strlen(arr0) - 1; i >= 0; i--) // ���������� 1-�� �����
		arr1[i] = arr0[strlen(arr0) - 1 - i];
	cout << "������� ������ ����� (�� 10 ��������)" << "\n";
	getline(cin, s2);arr0 = s2.data(); // ������ 2-�� �����
	for (int i = strlen(arr0) - 1; i >= 0; i--) // ���������� 2-�� �����
		arr2[i] = arr0[strlen(arr0) - 1 - i];
	

	// ���������� ����� ����� ��� ������ ������� ����������
	_asm
	{
		mov ESI, 0 //��������� ��������
	prime0:
		xor edx, edx
		mov dl, arr1[ESI] // ������ 1-�� �����
		add dl, arr2[ESI] // ������ 2-�� �����
		add dl, arr3[ESI] // ������������ ����������� ������� (���� ����, �� ������� '1', ����� '0')
		sub edx, '0'*3 // ��������� �����
		cmp edx, 9 // �������� �� ������������
		jbe prime1 // ���� ������������ ��� - �������
		// ������������ �������
		sub edx, 10 // ������� ������������
		mov arr3[ESI + 1], 1 + '0' //���������� �������� ������� (+1)
	prime1: // ������ ����� � ������� ������
		add edx, '0' // ����������� � ������
		mov arr3[ESI], dl // ���������� ������� � ������ ������
		inc ESI // ���������� �������
		cmp ESI, 9 // �������� �� ����� �� ������ (������� > 9)
		jbe prime0 // ����� ����������
	}


	// ���������� �������� ����� ��� ������ ������� ����������
	// !!!! ������ ����� >= ������� !!!!!
	_asm
	{
		mov ESI, 0 //��������� ��������
	prime00:
		xor edx, edx
		mov dl, arr1[ESI] // ������ 1-�� �����
		sub dl, arr2[ESI] // ������ 2-�� �����
		add dl, arr4[ESI] // "����" � ����������� �������
		cmp edx, '0' // �������� �� ����������
		jae prime11 // ���� ��� �� - �������
		// ����� ��p�� 1 �� �������� �������
		add edx, 10
		mov arr4[ESI + 1], '0' - 1 //���������� �������� ������� (-1)
	prime11: // ������ ����� � ������� ������
		mov arr4[ESI], dl // ���������� ������� � ������ ������
		inc ESI // ���������� �������
		cmp ESI, 9 // �������� �� ����� �� ������ (������� > 9)
		jbe prime00 // ����� ����������
	}


	// ��������� ����� ��� ������ ������� ����������
	// ��������� � 0, ���� �������� �������; �1, ���� ������ ����� ������ �������; 1, ���� ������ ����� ������ �������.
	_asm
	{
		// ���������� �������� ������ ����� ��������
		mov ESI, 10 // ����������� �������� - ������ ������� � �����
		xor ebx, ebx
	prime000: 
		//������ �����
		dec ESI // ���������� ��������
		xor edx, edx
		add edx, '0'
		add dl, arr1[ESI] // ������ 1-�� �����
		sub dl, arr2[ESI] // ������ 2-�� �����
		cmp edx, '0' // ���������� � '0'
		jb prime111 // edx < '0', ���� ������ 2-�� ����� ������ -> 2-� ����� ������, �������
		je prime444 // edx == '0' -> ����� ������� ��������� -> ����������
		jne prime333
	prime444: 
		cmp ESI, 0 // �������� ������ ��������?
		jne prime000 // ��� - ���������� ���������
		je prime222 // ����� �������
		// ����� �����
	prime111: // ����� ����� 2-� ����� ������
		mov result, -1 // ���������� ���������
	prime222:
		cmp edx, '0' // edx == '0' -> ����� ���� �������� ��������� -> ����� �����
		jne prime333 // ����� ��������� ��� ��������
		mov result, 0
	prime333:
	}
	//�����
	cout << "\n";
	cout << "����� �����:" << "\n";
	print(arr3);
	cout << "�������� �����:" << "\n";
	if (result == -1)
		cout << "�� ����� ���� ���������. �. �. ������ ����� ������ �������." << "\n";
	else
		print(arr4);
	cout << "���������: " << result;
	cout << "\n";
	cout << "��������� ��������� � 0, ���� �������� �������; �1, ���� ������ ����� ������ �������; 1, ���� ������ ����� ������ �������." << "\n";
	cout << "\n";
	
	return 0;
}

