#include <iostream>
using namespace std;

template<class T>
T Add(T x, T y);

template
int Add(int x, int y);
template
double Add(double x, double y);