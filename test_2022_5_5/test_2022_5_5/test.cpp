#include "Grap.h"

int main()
{
	int arr[8][8] = { 0 };
	
	//while (1)
	//{
	//	LetterSin(arr);
	//	PrintArray(arr);
	//	Sleep(50);
	//	system("cls");
	//	int count = 8;
	//	while (count--)
	//	{
	//		PlaneMoveLeft(arr);
	//		PrintArray(arr);
	//		Sleep(50);
	//		system("cls");
	//	}
	//	LetterLogic(arr);
	//	PrintArray(arr);
	//	Sleep(50);
	//	system("cls");
	//	count = 8;
	//	while (count--)
	//	{
	//		PlaneMoveLeft(arr);
	//		PrintArray(arr);
	//		Sleep(50);
	//		system("cls");
	//	}
	//}
	while (1)
	{
		Book1(arr);
		PrintArray(arr);
		Sleep(200);
		system("cls");
		Book2(arr);
		PrintArray(arr);
		Sleep(200);
		system("cls");
		Book3(arr);
		PrintArray(arr);
		Sleep(200);
		system("cls");
		Book4(arr);
		PrintArray(arr);
		Sleep(200);
		system("cls");
	}
	LetterSin(arr);
	PrintArray(arr);
	return 0;
}
