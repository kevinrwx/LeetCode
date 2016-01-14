
//Compare Version Numbers

#include <iostream>
#include <vector>

using namespace std;

int string2Int(string str) {
	int result = 0;
	int length = str.length();
	for(int i = 0; i < length; i++)
		result = result*10 + (str[i] - '0');
	return result;
}

vector<int> split(string str, string splits) {
	vector<int> result;
	int length = str.length();
	int i = 0;
	int index = 0;
	while(i < length) {
		if(str[i] == splits[0]) {
			string tmp = str.substr(index, i-index);
			result.push_back(string2Int(tmp));
			index = i + 1;
		}
		i++;
	}
	string tmp = str.substr(index, i-index);
	result.push_back(string2Int(tmp));
	return result;
}

int compareVersion(string version1, string version2) {
	int length1 = version1.length();
	int length2 = version2.length();
	string splits = ".";
	vector<int> result1 = split(version1, splits);
	vector<int> result2 = split(version2, splits);
	int size1 = result1.size();
	int size2 = result2.size();
	int size = min(size1, size2);
	for(int i = 0; i < size; i++) {
		if(result1[i] < result2[i])
			return -1;
		else if(result1[i] > result2[i])
			return 1;
		else
			continue;
	}
	if(size1 < size2) {
		for(int i = size1; i < size2; i++) {
			if(result2[i] != 0)
				return -1;
		}
		return 0;
	}
	else if(size1 > size2) {
		for(int i = size2; i < size1; i++) {
			if(result1[i] != 0)
				return 1;
		}
		return 0;
	}
	else
		return 0;
}

int main() {
	//
}