
//Binary Search Tree Iterator

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//最笨的方法，首先中序遍历二叉树，并将结果存放在队列中，然后就方便用hasNext()和next()进行判断了
class BSTIterator {
public:
	queue<int> minq;
	unordered_map<TreeNode*, bool> mapping;
	stack<TreeNode*> s;

	BSTIterator(TreeNode* root) {
		if(root != NULL) {
			TreeNode* cur = root;
			bool done = false;
			while(!done) {
				if(cur != NULL) {
					s.push(cur);
					cur = cur->left;
					mapping[cur] = true;
				} else {
					if(!s.empty()) {
						cur = s.top();
						s.pop();
						minq.push(cur->val);
						mapping[cur] = true;
						cur = cur->right;
					} else {
						done = true;
					}
				}
			}
		}
	}

	bool hasNext() {
		return !minq.empty();
	}

	int next() {
		int front = minq.front();
		minq.pop();
		return front;
	}
};

//这道题属于非递归二叉树中序遍历的变体，具体的非递归遍历方法在下面
class BSTIterator {
public:
	stack<TreeNode*> st;
	int nextmin;

	BSTIterator(TreeNode* root) {
		while(root != NULL) {
			st.push(root);
			root = root->left;
		}
	}

	bool hasNext() {
		if(!st.empty()) {
			TreeNode* top = st.top();
			st.pop();
			nextmin = top->val;
			TreeNode* cur = top->right;
			if(cur != NULL) {
				st.push(cur);
				cur = cur->left;
				while(cur != NULL) {
					st.push(cur);
					cur = cur->left;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	int next() {
		return nextmin;
	}
};

//二叉树递归遍历的方法
// void inorderTraversal(TreeNode* root) {
// 	if(root != NULL) {
// 		inorderTraversal(root->left);
// 		cout<<root->val<<" ";
// 		inorderTraversal(root->right);
// 	}
// }

// void inorderTraversal(TreeNode* root, vector<int>& nums) {
// 	if(root != NULL) {
// 		inorderTraversal(root->left, nums);
// 		nums.push_back(root->val);
// 		inorderTraversal(root->right, nums);
// 	}
// }

//非递归方法中序遍历二叉树
// vector<int> inorderTraversal(TreeNode* root)
// {
// 	vector<int> nums;
// 	stack<TreeNode*> mystack;
// 	if(root == NULL)
// 		return nums;
// 	TreeNode* cur = root;
// 	bool done = false;
// 	while(!done) {
// 		if(cur != NULL) {
// 			mystack.push(cur);
// 			cur = cur->left;
// 		}
// 		else {
// 			if(!mystack.empty()) {
// 				cur = mystack.top();
// 				mystack.pop();
// 				nums.push_back(cur->val);
// 				cur = cur->right;
// 			}
// 			else
// 				done = true;
// 		}
// 	}
// 	return nums;
// }

// TreeNode* arr2Tree(int nums[], int l, int r) {
// 	if(l <= r) {
// 		int mid = l + (r - l) / 2;
// 		TreeNode* root = new TreeNode(nums[mid]);
// 		root->left = arr2Tree(nums, l, mid-1);
// 		root->right = arr2Tree(nums, mid+1, r);
// 		return root;
// 	}
// 	return NULL;
// }

// void printVector(vector<int>& nums) {
// 	int length = nums.size();
// 	if(length <= 0)
// 		cout<<"empty vector";
// 	for(int i = 0; i < length; i++)
// 		cout<<nums[i]<<" ";
// 	cout<<endl;
// }

// int main() {
// 	int nums[] = {1, 2, 3, 4, 5, 6, 7};
// 	int n = sizeof(nums) / sizeof(nums[0]);
// 	TreeNode* root = arr2Tree(nums, 0, n-1);
// 	vector<int> result = inorderTraversal(root);
// 	printVector(result);
// 	return 0;
// }



