
//Unique Paths 

#include <iostream>

using namespace std;

//Method I 由于是递归调用，而且涉及到了重复计算，所以当m和n的数值比较大时，程序会超时
// int uniquePaths(int m, int n)
// {
// 	if(m == 1 || n == 1)
// 		return 1;
// 	else
// 		return uniquePaths(m-1, n) + uniquePaths(m, n-1);
// }


//Method II存储以前的结果，而且把二维的存储空间降成了一维的存储空间
int uniquePaths(int m, int n)
{
	if(m == 1 || n == 1)
		return 1;
	int *tmp = new int[m+1];
	for(int i = 1; i <= m; i++)
		tmp[i] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			tmp[j] = tmp[j] + tmp[j-1];
		}
	}
	int result = tmp[m];
	delete []tmp;
	return result;
}

int main()
{
	int m = 3;
	int n = 3;
	int result = uniquePaths(m, n);
	cout<<result<<endl;
}