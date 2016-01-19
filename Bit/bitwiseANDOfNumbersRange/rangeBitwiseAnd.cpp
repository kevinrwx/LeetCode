
//Bitwise AND of Numbers Range

#include <iostream>

using namespace std;

//刚看到这道题目时，觉得思路很简单，那就从m遍历到n，挨个按位与呗，但是最后提交代码时，提示超时
//后来转变思路，由于最后的结果很多都是0，所以我们就没有必要挨个去遍历，我们先从n开始遍历，将n与n-1进行
//按位与，接着将按位与的结果赋给n，接下来再重复前面的步骤，直到n变成0，然后再比较tmp跟m的大小，如果比m
//大，那最后的结果肯定是0，所以直接返回0就可以了，如果不是0，那就按部就班的挨个遍历就行了

//上面的思路是来自log(n)复杂度来统计一个数字中1的个数，具体思路如下：对于二进制数1000，若减1，则变
//为0111，就是说，对于二进制的减1，就是从末尾开始寻找1，寻找的过程中，凡是0位都变成1。直到寻找到第一
//个1，把它变为0，则这次减1运算完毕。对于数1100，对其减1，变为1011，将此结果和原数1100做&操作，得
//到1000，我们发现末尾的第一个1就没有了。重复这个动作，直到结果变成0，这个减1动作的重复次数，就是1的个数。

//注意点：在按部就班的遍历时，为了防止超过INT_MAX的上限，要将i赋值为long long类型
// int rangeBitwiseAnd(int m, int n) {
// 	int tmp;
// 	int top = n;
// 	while(top != 0) {
// 		tmp = top - 1;
// 		top &= tmp;
// 	}
// 	if(tmp >= m)
// 		return 0;
// 	int result = m;
// 	for(long long i = m; i <= n; i++) {
// 		result &= i;
// 	}
// 	return result;
// }


//网上的牛叉方法，思路就是求m与n二进制编码中同为1的前缀，分别将m和n向右按位移动，如果相等，那么就把m和n的
//相同前缀剩余了下来，这就是m到n之间所有数字的相同前缀，即使你将m到n之间所有数字按位与以后，这些前缀也会保
//留下来，将这些前缀再左移一定的位数以后，这就是最后的结果
int rangeBitwiseAnd(int m, int n) {
	int bit = 0;
	while(m != n) {
		m >>= 1;
		n >>= 1;
		bit++;
	}
	return m << bit;
}

//参考链接：http://www.cnblogs.com/csonezp/p/4587392.html
//我刚开始思路的改进，这种改进也是从网上看到的，仍然是按位与，消除最后一位1的思路，只不过到n小于m时就结束了
int rangeBitwiseAnd(int m, int n) {
	while(n > m) {
		n = n & (n-1);
	}
	return n;
}

int main() {
	int m = 2000;
	int n = 2147483647;
	int result = rangeBitwiseAnd(m, n);
	// int result = m & n;
	cout<<result<<endl;
	return 0;
}