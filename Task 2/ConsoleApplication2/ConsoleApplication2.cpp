#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	// ����������
	char outp[12] = "          "; //
	int num; // �������� �����
	int ten = 10; // ����� 10
	int len = 10; // ���-�� �������� - 1;
	int znak = 0; // ���� ����� 0 - ���������������, 1 - �������������

	setlocale(LC_ALL, "RUS"); // ����� ������� ������� ����������
	cout << "������ 3" << "\n";
	cout << "��������� �������� ����� �� ������ �� ����������� ������������� � ���������� ������" << "\n";
	
	// ����
	cout <<  "������� ����� (�� 11 ��������)" << "\n";
	cin >> num;

	// ��������� ��������
	_asm
	{
		mov ESI, len // �����, � �������� ����� ��������� ������ (�����)
		xor eax, eax  //�������� ��������
		mov eax, num // ���������� ����� � �������
		test eax, eax // �������� ����� ����
		jns prime1 // ���� >= 0 �������
		//���� ����� �������������
		neg eax //����� ������ ���� �����
		mov znak, 1 //����������, ��� ����� �������������
	// ������ ����� - � ������
	prime1:
		//������ �����
		xor edx, edx //��������� ������� ����� �������� �����(�������)
		div ten //�������(EDX:EAX) / 10, ������� � EDX
		add edx, 30h //�������������� ������� � ��� �������
		mov outp[ESI], dl // ������ ������� � ������ � �����
		dec ESI //��������� ��������� �� 1
		cmp eax, 0 // ���� ����� != 0 ��������� ��������
		jne prime1
		// ����� �����

		mov dl, 43 // ���������� ��� '+'
		cmp znak, 0 // ��������� ���� ��������� �����
		je prime2 // ����� ������������� - �������
		mov dl, 45 // ���� ����� < 0 ���������� ��� '-'
	prime2:
		mov outp[ESI], dl //��������� ���� ����� � ������(������)
	}

	//�����
	cout << "���������:" << "\n";
	cout << outp << "\n";
    return 0;
}

