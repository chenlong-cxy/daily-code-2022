//队列的最大值
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (_dq.empty())
			return -1;
		return _dq.front();
	}

	void push_back(int value) {
		while (!_dq.empty() && _dq.back() < value)
		{
			_dq.pop_back();
		}
		_dq.push_back(value);
		_q.push(value);
	}

	int pop_front() {
		if (_q.empty())
			return -1;
		int front = _q.front();
		_q.pop();
		if (_dq.front() == front)
			_dq.pop_front();
		return front;
	}
private:
	std::queue<int> _q;
	std::deque<int> _dq;
};
int main()
{

	return 0;
}