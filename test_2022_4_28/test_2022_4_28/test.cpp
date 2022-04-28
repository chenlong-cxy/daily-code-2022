#include <iostream>
#include <vector>
#include "Grap.h"
using namespace std;

int main()
{
	int arr[8][8] = { 0 };
	CryFace(arr);
	cout << "¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ" << endl;
	for (int j = 7; j >= 0;j--)
	{
		cout << "¡õ";
		for (int i = 0; i < 8;i++)
		{
			if (arr[i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		cout << "¡õ";
		cout << endl;
	}
	cout << "¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ" << endl;
	return 0;
}
