
//unique binary search tree II

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//这种方法在求左右子树的时候进行了重复计算，导致运算量比较大，所以这道题目还有再优化的空间
vector<TreeNode*> genBST(int min, int max)
{
	vector<TreeNode*> results;
	if(min > max) {
		results.push_back(NULL);
		return results;
	}

	for(int i = min; i <= max; i++) {
		vector<TreeNode*> leftSubTree = genBST(min, i-1);
		vector<TreeNode*> rightSubTree = genBST(i+1, max);
		int leftSize = leftSubTree.size();
		int rightSize = rightSubTree.size();
		for(int j = 0; j < leftSize; j++) {
			for(int k = 0; k < rightSize; k++) {
				TreeNode* tmp = new TreeNode(i);
				tmp->left = leftSubTree[j];
				tmp->right = rightSubTree[k];
				results.push_back(tmp);
			}
		}
	}
	return results;
}


vector<TreeNode*> generateTrees(int n)
{
	return genBST(1, n);
}


int main() {
	//
}