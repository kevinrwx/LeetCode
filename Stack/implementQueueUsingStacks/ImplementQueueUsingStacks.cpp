//Implement Queue using Stacks

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
	stack<int> in;
	stack<int> out;

	void push(int x) {
		in.push(x);
	}

	void move() {
		while(!in.empty()) {
			int tmp = in.top();
			in.pop();
			out.push(tmp);
		}
	}

	void pop(void) {
		if(out.empty()) {
			move();
			out.pop();
		} else {
			out.pop();
		}
	}

	int peek() {
		if(out.empty()) {
			move();
			return out.top();
		} else {
			return out.top();
		}
	}

	bool empty(void) {
		return in.empty() && out.empty();
	}

};

int main() {
	cout<<"haha";
	return 0;
}
