// Task8.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������ 8" << "\n";
	cout << "������������ ������ ������ � �������� ��������� �� ����������/������������" << "\n";

	// ����������
	char s[120]; // ������ �����
	char sout[120] = { ' ' }; // ������ ������
	char  a[63] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890"; // ������� �������� ��������
	char  b[63] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm3456789012"; // ������� ����������

																					// ����
	cout << "������� ������" << "\n";
	fgets(s, 120, stdin);
	cout << "����� ����������� ������ ������� 1, ����������� - 2" << "\n";
	int n;
	cin >> n;

	if (n == 1) // ����������
	{
		// ����������
		__asm
		{
			mov edx, 0 // edx - ������� ������
			mov ESI, edx
			xor eax, eax
			mov al, s[ESI] // al - ������� ������� ������
			prime0:
			// ������ ����� �������� �������� ������
			xor ecx, ecx // edc - ������� �������� ����������
				prime3 :
			// ������ ����� �������� �������� ��������
			mov ESI, ecx
				inc ecx // ���������� ��������
				cmp al, a[ESI] // ��������� ������� �������� ������ � ��������
				jne prime3 // ����� ����� �������� �������� �� ������ �� �� ��������, ����� �������� ������������
						   // ����� �����
				mov bl, b[ESI] // bl - ����� �������
				mov ESI, edx // �������� ������
				mov sout[ESI], bl // ������ ������ �������
				inc edx // ���������� ��������
				mov ESI, edx
				xor eax, eax // �������� ��������
				mov al, s[ESI] // ��������� ��������� ������ ������
				cmp ax, 0 // �������� �� ����� ������
				jne prime0
				// ����� �����
		}

		//�����
		cout << "��������� ����������:" << "\n" << sout << "\n";
	}
	else if (n == 2) // ������������
	{
		// ������������
		__asm
		{
			mov edx, 0 // edx - ������� ������
			mov ESI, edx
			xor eax, eax
			mov al, s[ESI] // al - ������� ������� ������
			prime1:
			// ������ ����� �������� �������� ������
			xor ecx, ecx // edc - ������� �������� ������������
				prime2 :
			// ������ ����� �������� �������� ��������
			mov ESI, ecx
				inc ecx // ���������� ��������
				cmp al, b[ESI] // ��������� ������� �������� ������ � ��������
				jne prime2 // ����� ����� �������� �������� �� ������ �� �� ��������, ����� �������� ������������
						   // ����� �����
				mov bl, a[ESI] // bl - ����� �������
				mov ESI, edx // ������� ������
				cmp bl, 122 // ��������� ������ �� ������ � ������� (122 ��� 'z')
				ja prime4 // �� ��� ������, �������� ������, �� ��� ��� � ����� ������ ������������ ������� �
						  // ��� ����� �������, ��� ��� ������ �� ����������� ��� ����������
				mov sout[ESI], bl // ������ ������ �������
				inc edx // ���������� ��������
				mov ESI, edx
				xor eax, eax // �������� ��������
				mov al, s[ESI] // ��������� ��������� ������ ������
				cmp ax, 0 // �������� �� ����� ������
				jne prime1
				// ����� �����
				prime4 :
		}
		//�����
		cout << "��������� ������������:" << "\n" << sout << "\n";
	}
	else
		cout << "������!" << "\n";
	return 0;
}
