
//Rectangle Area

#include <iostream>
#include <vector>

using namespace std;

int area(int A, int B, int C, int D) {
	return (C-A) * (D-B);
}

//本来是一道很简单的题目，但是由于判断条件太麻烦，导致提交时一直过不了
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int areaA = area(A, B, C, D);
	int areaB = area(E, F, G, H);
	int W = 0, X = 0, Y = 0, Z = 0;
	vector<int> length;
	length.push_back(A);
	length.push_back(C);
	length.push_back(E);
	length.push_back(G);
	sort(length.begin(), length.end());
	vector<int> width;
	width.push_back(B);
	width.push_back(D);
	width.push_back(F);
	width.push_back(H);
	sort(width.begin(), width.end());
	if((C-A)+(G-E) > max(abs(G-A), abs(E-C))) {
		W = length[1];
		Y = length[2];
	}
	if((D-B)+(H-F) > max(abs(H-B), abs(D-F))) {
		X = width[1];
		Z = width[2];
	}
	int overlap = area(W, X, Y, Z);
	return (areaA + areaB - overlap);
}

int main() {
	int A = 4, B = -5, C = 5, D = 0;
	int E = -3, F = -3, G = 3, H = 3;
	int result = computeArea(A, B, C, D, E, F, G, H);
	cout<<result<<endl;
	return 0;
}