// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// Task 2.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//string s = "";
	cout << "Vvedite stroku" << "\n";
	//getline(cin, s);
	//s.reserve();
	//int kol = sizeof(s);
	string n = "12345";
	//int kol = sizeof(n);
	char inp[10] = "12345";
	char news[8]; // 
	int output;
	int znak = 1;
	int ten = 10;
	__asm
	{
		xor eax, eax // suda zapishem
		xor ebx, ebx
		//mov ecx, kol
		xor esi, esi
		cmp inp[esi], '+' // ravni
		je prime1
		mov znak, -1 //
	prime1:
		//dec ecx //kol --
		inc esi //i++
		mov bl, inp[esi] //ebx
		cmp bl, 0 // ne ravno inache vihod
		je prime2 // if i>n
		sub bl, '0'
		mul ten //?
		add eax, ebx // bl?
		jmp prime1
	prime2 :
		mov ebx, znak
		mul bx //?? *10
		mov output, eax //al ???
	//primeend:
		
	}
	cout << output;
	return 0;
}