
//Happy Number

#include <iostream>
#include <unordered_set>

using namespace std;

//思路比较直接，就是按照题意依次计算就可以了，其中麻烦的是如果不是happy number怎么办？我们可以用一个set来存放
//每次计算的结果，如果遇到重复的结果，这就说明happy number的计算进入了循环，所以遇到循环时直接跳出就行了
bool isHappy(int n) {
	unordered_set<int> setting;
	while(n != 1) {
		if(setting.find(n) == setting.end()) {
			setting.insert(n);
			int tmp = 0;
			while(n != 0) {
				tmp += pow(n % 10, 2);
				n /= 10;
			}
			n = tmp;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	int n = 19;
	bool result = isHappy(n);
	if(result)
		cout<<"happy number"<<endl;
	else
		cout<<"not happy"<<endl;
	return 0;
}