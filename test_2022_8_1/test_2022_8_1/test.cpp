#include "Sort.h"

int main()
{
	vector<int> v{ 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	QuickSort1(v, 0, v.size()-1);
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
