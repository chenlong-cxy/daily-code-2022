#include <iostream>
#include <vector>
#include "Grap.h"
using namespace std;

int main()
{
	int arr[8][8] = { 0 };
	CryFace(arr);
	cout << "��������������������" << endl;
	for (int j = 7; j >= 0;j--)
	{
		cout << "��";
		for (int i = 0; i < 8;i++)
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
	return 0;
}
