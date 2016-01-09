
//min stack

#include <iostream>
#include <stack>

using namespace std;

class minStack
{
public:
	//首先声明这道题目并不是我独立想出来的，是在看完题解以后做出来的，而且没有写main函数进行测试
	//这道题目的思路就是再用一个额外的栈来存放最小的元素，即增加一个stack<int> min，则每次往st
	//中push元素时，还要判断这个元素是不是比当前的最小元素要小，如果是的话，还要把这个元素再push
	//到min中，否则，就只push到st中；同理，在pop元素时，也要判断pop的元素是否比当前的最小元素小
	//如果是的话，还要把min中的当前最小元素pop出去，对于top和getMin这两个函数就比较简单了，可以
	//直接写
	void push(int x) {
		st.push(x);
		if(min.empty() || min.top() >= x)
			min.push(x);
	}

	void pop() {
		int top = st.top();
		st.pop();
		if(top <= min.top())
			min.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int> st;
	stack<int> min;
};
