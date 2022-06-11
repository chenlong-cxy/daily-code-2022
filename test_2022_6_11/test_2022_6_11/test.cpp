#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int tickets = 1000;

void handler()
{
	static mutex mtx;
	while (1){
		mtx.lock();
		if (tickets > 0){
			cout << --tickets << endl;
			mtx.unlock();
		}
		else{
			mtx.unlock();
			break;
		}
	}

}
int main()
{
	thread t1(handler);
	thread t2(handler);
	t1.join();
	t2.join();
	return 0;
}