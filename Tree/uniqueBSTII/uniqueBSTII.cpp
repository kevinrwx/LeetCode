
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

void addUp(TreeNode* tree, int gap) {
	//
}

vector<TreeNode*> treesAdd(vector<TreeNode*> trees, int gap) {
	if(gap == 0)
		return trees;
	int len = trees.size();
	vector<TreeNode*> results;
	for(int i = 0; i < len; i++) {
		addUp(trees[i], gap);
		results.push_back(trees[i]);
	}
	return results;
}

vector<TreeNode*> generateTrees(int n) {
	vector<vector<TreeNode*> > results;
	vector<TreeNode*> temp; //用空值填充results[0]
	results.push_back(temp);
	TreeNode* node = new TreeNode(1);
	temp.push_back(node);	//给results[0]赋值
	results.push_back(temp);
	for(int i = 2; i <= n; i++) {
		vector<TreeNode*> tmp;
		vector<TreeNode*> Left = results[i-1];
		vector<TreeNode*> Right = treesAdd(results[n-i], i);
		int lenL = Left.size();
		int lenR = Right.size();
		for(int j = 0; j < lenL; j++) {
			for(int k = 0; k < lenR; k++) {
				TreeNode* node = new TreeNode(i);
				node->left = Left[j];
				node->right = Right[k];
				tmp.push_back(node);
			}
		}
		results.push_back(tmp);
	}
}

int main() {
	//
}