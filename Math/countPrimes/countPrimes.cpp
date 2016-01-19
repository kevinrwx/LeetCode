
//Count Primes

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// bool isPrime(int n) {
// 	int top = pow(n, 0.5);
// 	for(int i = 2; i <= top; i++) {
// 		if(n % i == 0)
// 			return false;
// 	}
// 	return true;
// }
// //初始的思路就是挨个判断，但是这种方法耗时较长，提交后的代码会超时
// int countPrimes(int n) {
// 	int counts = 0;
// 	for(int i = 1; i <= n; i += 2) {
// 		if(isPrime(i))
// 			counts++;
// 	}
// 	return counts;
// }


//另外一种方法是埃拉托斯特尼筛法，下面是伪代码
//for i = 2, 3, 4, ...,sqrt(n):
//  if num[i] is true:
//     for j = i*i, i*i+i, i*i+2i....n
//			A[j] = false
//Output: all i such that A[i] is true
int countPrimes(int n) {
	if(n <= 1)
		return 0;
	int limit = sqrt(n);
	int counts = 0;
	vector<bool> num(n, true);
	for(int i = 2; i <= limit; i++) {
		if(num[i]) {
			for(int j = i*i; j <= n; j += i)
				num[j] = false;
		}
	}
	for(int i = 2; i < n; i++)
		if(num[i])
			counts++;
	return counts;
}

int main() {
	int n = 2;
	int result = countPrimes(n);
	cout<<result<<endl;
	return 0;
}