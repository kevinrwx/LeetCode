
//Binary Tree Inorder Traversal 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void copyVector(vector<int>& srcVec, vector<int>& desVec)
{
	for(int i = 0; i < srcVec.size(); i++)
		desVec.push_back(srcVec[i]);
}

//Recursive Way
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> nums;
	vector<int> tmp;
	if(root == NULL)
		return tmp;
	tmp = inorderTraversal(root->left);
	copyVector(tmp, nums);
	nums.push_back(root->val);
	tmp = inorderTraversal(root->right);
	copyVector(tmp, nums);
	return nums;
}

//another recursive way
void inorder(TreeNode* root, vector<int>& nums) {
	if(root != NULL) {
		inorderTraversal(root->left, nums);
		nums.push_back(root->val);
		inorderTraversal(root->right, nums);
	}
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> results;
	if(root == NULL)
		return results;
	inorder(root, results);
	return results;
}


//Iteratively Way
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> nums;
	stack<TreeNode*> mystack;
	if(root == NULL)
		return nums;
	TreeNode* cur = root;
	bool done = false;
	while(!done) {
		if(cur != NULL) {
			mystack.push(cur);
			cur = cur->left;
		}
		else {
			if(!mystack.empty()) {
				cur = mystack.top();
				mystack.pop();
				nums.push_back(cur->val);
				cur = cur->right;
			}
			else
				done = true;
		}
	}
	return nums;
}



void printVector(vector<int>& nums)
{
	int lens = nums.size();
	if(lens == 0 )
		cout<<"Empth Vector"<<endl;
	for(int i = 0; i < lens; i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}

int main()
{
	vector<int> results;
	struct TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	cout<<"The inorderTraversal is: ";
	results = inorderTraversal(root);
	printVector(results);
	return 0;


}
