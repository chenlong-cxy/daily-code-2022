#include "Grap.h"

int main()
{
	int arr[8][8] = { 0 };
	while (1)
	{
		PlaneBoxPro1(arr);
		PrintArray(arr);
		Sleep(100);
		system("cls");
		PlaneBoxPro2(arr);
		PrintArray(arr);
		Sleep(100);
		system("cls");
		PlaneBoxPro3(arr);
		PrintArray(arr);
		Sleep(100);
		system("cls");
		PlaneBoxPro4(arr);
		PrintArray(arr);
		Sleep(100);
		system("cls");
	}
	return 0;
}
