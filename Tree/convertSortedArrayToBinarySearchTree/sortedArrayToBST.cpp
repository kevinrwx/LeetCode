
//Convert Sorted Array to Binary Search Tree

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* arrayToBST(vector<int> &nums, int start, int end)
{
	if(start > end)
		return NULL;
	if(start == end)
		return new TreeNode(nums[start]);
	int mid = start + (end - start) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = arrayToBST(nums, start, mid-1);
	root->right = arrayToBST(nums, mid+1, end);
	return root;
}

TreeNode* sortedArrayToBST(vector<int> &nums)
{
	int len = nums.size();
	if(len == 0)
		return NULL;
	return arrayToBST(nums, 0, len - 1);
}

void levelOrder(TreeNode* root)
{
	if(root == NULL)
		cout<<"empty tree";
	else {
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			cout<<tmp->val<<" ";
			if(tmp->left != NULL)
				q.push(tmp->left);
			if(tmp->right != NULL)
				q.push(tmp->right);
		}
	}
}

vector<int> arrToVector(int nums[], int n)
{
	vector<int> results;
	for(int i = 0; i < n; i++)
		results.push_back(nums[i]);
	return results;
}


int main()
{
	int nums[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(nums) / sizeof(nums[0]);
	vector<int> numsVect;
	numsVect = arrToVector(nums, n);
	TreeNode* root = sortedArrayToBST(numsVect);
	levelOrder(root);
	return 0;
}