#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void PlaneNum0(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 6) && (i == 3 || i == 4))
				arr[i][j] = 1;
			else if ((i == 2 || i == 5) && (j != 7))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum1(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j != 7 && i == 5)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum2(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if (((j == 1 || j == 2) && (i == 2)) || ((j == 4 || j == 5) && (i == 5)))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum3(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if ((j == 1 || j == 2 || j == 4 || j == 5) && (i == 5))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum4(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j != 7 && i == 5)
				arr[i][j] = 1;
			else if ((j == 3 || j == 4 || j == 5 || j == 6) && (i == 2))
				arr[i][j] = 1;
			else if (j == 3 && (i == 3 || i == 4))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum5(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if (((j == 1 || j == 2) && (i == 5)) || ((j == 4 || j == 5) && (i == 2)))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum6(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if (((j == 1 || j == 2) && (i == 2 || i == 5)) || ((j == 4 || j == 5) && (i == 2)))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum7(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j != 7 && i == 5)
				arr[i][j] = 1;
			else if (j == 6 && (i == 2 || i == 3 || i == 4))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum8(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if (((j == 1 || j == 2) && (i == 2 || i == 5)) || ((j == 4 || j == 5) && (i == 2 || i == 5)))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneNum9(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 0 || j == 3 || j == 6) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if (((j == 1 || j == 2) && (i == 5)) || ((j == 4 || j == 5) && (i == 2 || i == 5)))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneCircle(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 2 || j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((j == 0 || j == 7) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if ((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneHeart(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 3 || i == 4) && (j != 6 && j != 7))
				arr[i][j] = 1;
			else if ((i == 2 || i == 5) && (j != 0 && j != 7))
				arr[i][j] = 1;
			else if ((i == 1 || i == 6) && (j != 0 && j != 1 && j != 7))
				arr[i][j] = 1;
			else if ((i == 0 || i == 7) && (j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneWhole(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arr[i][j] = 1;
		}
	}
}
void UsualFace(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 2 || j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((j == 0 || j == 7) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if ((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6))
				arr[i][j] = 1;
			else if ((i == 2 && j == 5) || (i == 5 && j == 5))
				arr[i][j] = 1;
			else if (i >= 2 && i <= 5 && j == 3)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void SmileFace(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 2 || j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((j == 0 || j == 7) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if ((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6))
				arr[i][j] = 1;
			else if ((i == 2 && j == 5) || (i == 5 && j == 5))
				arr[i][j] = 1;
			else if ((i == 2 || i == 5) && j == 3)
				arr[i][j] = 1;
			else if ((i == 3 || i == 4) && j == 2)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void CryFace(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 2 || j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((j == 0 || j == 7) && (i == 2 || i == 3 || i == 4 || i == 5))
				arr[i][j] = 1;
			else if ((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6))
				arr[i][j] = 1;
			else if ((i == 2 && j == 5) || (i == 5 && j == 5))
				arr[i][j] = 1;
			else if ((i == 2 || i == 5) && j == 2)
				arr[i][j] = 1;
			else if ((i == 3 || i == 4) && j == 3)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PrintArray(int arr[8][8])
{
	cout << "��������������������" << endl;
	for (int j = 7; j >= 0; j--)
	{
		cout << "��";
		for (int i = 0; i < 8; i++)
		{
			if (arr[i][j] == 1)
				cout << "��";
			else
				cout << "  ";
		}
		cout << "��";
		cout << endl;
	}
	cout << "��������������������" << endl;
}
void Windmill1(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0) && (j == 4 || j == 5 || j == 6))
				arr[i][j] = 0;
			else if ((i == 1) && (j == 0 || j == 4 || j == 5))
				arr[i][j] = 0;
			else if ((i == 2) && (j == 0 || j == 1 || j == 4))
				arr[i][j] = 0;
			else if ((i == 3) && (j == 0 || j == 1 || j == 2))
				arr[i][j] = 0;
			else if ((i == 4) && (j == 5 || j == 6 || j == 7))
				arr[i][j] = 0;
			else if ((i == 5) && (j == 3 || j == 6 || j == 7))
				arr[i][j] = 0;
			else if ((i == 6) && (j == 2 || j == 3 || j == 7))
				arr[i][j] = 0;
			else if ((i == 7) && (j == 1 || j == 2 || j == 3))
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}
}
void Windmill2(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0) && (j == 4))
				arr[i][j] = 1;
			else if ((i == 1) && (j == 2 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((i == 2) && (j == 1 || j == 2 || j == 4 || j == 5 || j == 6))
				arr[i][j] = 1;
			else if ((i == 3) && (j == 0 || j == 1 || j == 2 || j == 3 || j == 4))
				arr[i][j] = 1;
			else if ((i == 4) && (j == 3 || j == 4 || j == 5 || j == 6 || j == 7))
				arr[i][j] = 1;
			else if ((i == 5) && (j == 1 || j == 2 || j == 3 || j == 5 || j == 6))
				arr[i][j] = 1;
			else if ((i == 6) && (j == 2 || j == 3 || j == 5))
				arr[i][j] = 1;
			else if ((i == 7) && (j == 3))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBox1(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0) || (i == 7) || (j == 0) || (j == 7))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBox2(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j == 3) || (i + j == 11) || (i == j + 4) || (i + 4 == j))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBox3(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == 3 || i == 4 || j == 3 || j == 4)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}

void PlaneBoxPro1(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == 3 || i == 4 || j == 3 || j == 4)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBoxPro2(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == 2 || i == 5 || j == 2 || j == 5)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBoxPro3(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == 1 || i == 6 || j == 1 || j == 6)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneBoxPro4(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == 0 || i == 7 || j == 0 || j == 7)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterC(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((j == 1 || j == 6) && (i==2||i==3||i==4||i==5))
				arr[i][j] = 1;
			else if ((j == 2 || j == 3||j==4||j==5) && (i == 1))
				arr[i][j] = 1;
			else if ((j == 2 || j == 5) && (i == 6))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterW(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 2 || j == 3 || j == 4 || j == 5 || j == 6))
				arr[i][j] = 1;
			else if ((i == 1 || i == 6) && (j == 1))
				arr[i][j] = 1;
			else if ((i == 2 || i == 5) && (j == 2 || j == 3))
				arr[i][j] = 1;
			else if ((i == 3 || i == 4) && (j == 4 || j == 5))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterN(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 1 || i == 6) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 5 || j == 6))
				arr[i][j] = 1;
			else if ((i == 2) && (j == 5))
				arr[i][j] = 1;
			else if ((i == 3) && (j == 4))
				arr[i][j] = 1;
			else if ((i == 4) && (j == 3))
				arr[i][j] = 1;
			else if ((i == 5) && (j == 2))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterU(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 1 || i == 6) && (j == 2 || j == 3 || j == 4 || j == 5 || j == 6))
				arr[i][j] = 1;
			else if ((i == 2 || i == 3 || i == 4 || i == 5) && (j == 1))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterGO(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 5 || i == 7) && (j == 2 || j == 3 || j == 4))
				arr[i][j] = 1;
			else if ((i == 1 || i == 2 || i == 3 || i == 5 || i == 6 || i == 7) && (j == 1 || j == 5))
				arr[i][j] = 1;
			else if ((i == 3) && (j == 2 || j == 3))
				arr[i][j] = 1;
			else if ((i == 2) && (j == 3))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void LetterSin(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 1 || i == 2) && (j == i + 3))
				arr[i][j] = 1;
			else if ((i == 2 || i == 3 || i == 4 || i == 5 || i == 6) && (i + j == 7))
				arr[i][j] = 1;
			else if ((i == 7) && (j == 2))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void PlaneMoveLeft(int arr[8][8])
{
	int tmp[8], i, j;
	for (i = 0; i < 8; i++)
	{
		tmp[i] = arr[0][i];
	}
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}
	for (i = 0; i < 8; i++)
	{
		arr[7][i] = tmp[i];
	}
}
void LetterLogic(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 4) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 5))
				arr[i][j] = 1;
			else if ((i == 1 || i == 2 || i == 3) && (j == 5))
				arr[i][j] = 1;
			else if ((i == 5 || i == 6 || i == 7) && (j == 1))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void Book1(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 3)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void Book2(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 3)
				arr[i][j] = 1;
			else if ((i == 4 || i == 5 || i == 6) && (j == i))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void Book3(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 3)
				arr[i][j] = 1;
			else if ((i == 3) && (j == 4 || j == 5 || j == 6 || j == 7))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
void Book4(int arr[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 3)
				arr[i][j] = 1;
			else if ((i == 0 || i == 1 || i == 2) && (i + j == 6))
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}