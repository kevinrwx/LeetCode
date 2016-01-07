
//reverse word

#include <iostream>
#include <stack>

using namespace std;

//这种方法比较直接，使用额外的栈来存储每个单词，然后再将栈中的单词弹出，并填充到clear后的s中
//这种思路虽然比较简单，但是不满足题目要求的仅使用o(1)空间的要求，所以我们还需要继续优化这道题目的答案
// void reverseWords(string& s) {
// 	stack<string> st;
// 	int i = 0;
// 	string tmp;
// 	s.push_back(' ');
// 	int length = s.length();
// 	while(i < length) {
// 		if(s[i] == ' ') {
// 			i++;
// 			if(tmp.length() > 0) {
// 				st.push(tmp);
// 				tmp.clear();
// 			}
// 		}
// 		else {
// 			tmp.push_back(s[i]);
// 			i++;
// 		}
// 	}
// 	s.clear();
// 	while(!st.empty()) {
// 		string tmp = st.top();
// 		st.pop();
// 		for(int i = 0; i < tmp.length(); i++) {
// 			s.push_back(tmp[i]);
// 		}
// 		s.push_back(' ');
// 	}
// 	s = s.substr(0, s.length() - 1);
// }


//这种方法是满足题目要求的inplace方法，占用的额外空间为o(1)
void reverseWords(string& s) {
	int i = 0, j = s.length() - 1;
	//先去除string前面的空格
	while(i < s.length()) {
		if(s[i] == ' ')
			i++;
		else
			break;
	}
	//再去除string后面的空格
	while(j >= 0) {
		if(s[j] == ' ')
			j--;
		else
			break;
	}
	//s变成了去除首尾空格后的字符串
	s = s.substr(i, j-i+1);
	if(s.length() <= 0)
		return ;
	//再将字符串翻转
	i = 0, j = s.length() - 1;
	while(i < j) {
		char tmp = s[j];
		s[j--] = s[i];
		s[i++] = tmp;
	}
	//最后将字符串中的每个单词进行翻转
	string tmp;
	i = 0;
	s.push_back(' ');
	int length = s.length();
	int index = 0;
	while(i < length) {
		if(s[i] == ' ') {
			i++;
			if(tmp.length() > 0) {
				for(int j = tmp.length() - 1; j >= 0; j--)
					s[index++] = tmp[j];
				s[index++] = ' ';
				tmp.clear();
			}
		} else {
			tmp.push_back(s[i++]);
		}
	}
	s = s.substr(0, index-1);
}

int main() {
	string str = "   ";
	reverseWords(str);
	cout<<"**"<<str<<"**"<<endl;
	return 0;
}