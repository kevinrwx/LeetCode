
//Merge Sorted Array

#include <iostream>
#include <vector>

using namespace std;

//带返回值的merge函数，这样的函数看起来比较完整，只需要把原来两个的vector里的值merge到一个新的vector中就行了
//不需要再额外的拷贝数据
vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> tmp;
	int i = 0;
	int j = 0;
	while(i < m && j < n) {
		if(nums1[i] <= nums2[j]) {
			tmp.push_back(nums1[i]);
			i++;
		} else {
			tmp.push_back(nums2[j]);
			j++;
		}
	}
	while(i < m) {
		tmp.push_back(nums1[i++]);
	}
	while(j < n) {
		tmp.push_back(nums2[j++]);
	}
	return tmp;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for(int i = 0; i < m; i++) {
		nums2.push_back(nums1[i]);
	}
	int i = 0;
	int j = n;
	int k = 0;
	while(i < n && j < m+n) {
		if(nums2[i] <= nums2[j]) {
			nums1[k++] = nums2[i++];
		} else {
			nums1[k++] = nums2[j++];
		}
	}
	while(i < n) {
		nums1[k++] = nums2[i++];
	}
	while(j < m+n) {
		nums1[k++] = nums2[j++];
	}
}

void printVector(vector<int>& nums) {
	int length = nums.size();
	if(length <= 0)
		cout<<"empty vector";
	for(int i = 0; i < length; i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

int main() {
	vector<int> nums1(15, 0);
	nums1[0] = 1;
	nums1[1] = 3;
	nums1[2] = 5;
	nums1[3] = 7;
	nums1[4] = 9;
	// nums1.push_back(1);
	// nums1.push_back(3);
	// nums1.push_back(5);
	// nums1.push_back(7);
	// nums1.push_back(9);

	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(4);
	nums2.push_back(6);
	nums2.push_back(8);
	nums2.push_back(10);

	int m = 5;
	int n = nums2.size();

	merge(nums1, m, nums2, n);

	printVector(nums1);
	return 0;
}