
//unique binary search tree

#include <iostream>

using namespace std;


//递推方程为：sum(n) = sum(n-1)*sum(0) + sum(n-2)*sum(1) + .... + sum(1)*sum(n-2) + sum(0)*sum(n-1)
//sum(n-2)*sum(1)代表以(n-1)为根节点的BST个数
int countN(int nums[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum = sum + nums[i] * nums[n - 1 - i];
	return sum;
}

int numTrees(int n)
{
	int *nums = new int[n+1];
	nums[0] = 1;
	for(int i = 1; i <= n; i++)
		nums[i] = countN(nums, i);
	return nums[n];
	delete[] nums;
}

int main()
{
	int n = 3;
	int sum = numTrees(n);
	cout<<"sum: "<<sum<<endl;
	return 0;
}

