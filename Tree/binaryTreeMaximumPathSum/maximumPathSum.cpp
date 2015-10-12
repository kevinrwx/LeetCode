
 
//Binary Tree Maximum Path Sum

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int dfs(TreeNode* root, int* result) {
    if(root == NULL)
        return 0;
    int l = dfs(root->left, result);
    int r = dfs(root->right, result);
    int sum = root->val;
    if(l > 0)
        sum += l;
    if(r > 0)
        sum += r;
    *result = max(sum, *result);
    return max(l, r) > 0 ? max(l, r) + root->val : root->val;
}


//该问题的解决需要参照最大连续子序列和的方法
//先是递归的计算左子树的最大连续子序列和l，再递归的计算右子树的最大连续子序列和r，最后把l、r、root->val加起来
//最后在左子树和右子树递归的进行这一步骤，并更新最大值result
int maxPathSum(TreeNode* root) {
    if(root == NULL)
        return 0;
    int minimum = INT_MIN;
    int* result = &minimum;
    dfs(root, result);
    return *result;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    int result = maxPathSum(root);
    cout<<"The Result is: "<<result<<endl;
    return 0;
}



// //最大连续子序列和
// #include <iostream>
// #include <vector>

// using namespace std;

// //tmp代表以nums[i]结尾的连续子序列和的最大值
// //则tmp = max(tmp+nums[i], nums[i])，该
// //公式就是递推公式，同时再维护着一个maximum表
// //示最大值
// int maxConSubSum(vector<int> &nums) {
//     int length = nums.size();
//     if(length == 0)
//         return 0;
//     int tmp = nums[0];
//     int maximum = nums[0];
//     for(int i = 1; i < length; i++) {
//         tmp = max(tmp+nums[i], nums[i]);
//         if(tmp > maximum)
//             maximum = tmp;
//     }
//     return maximum;
// }

// int main() {
//     vector<int> nums;
//     nums.push_back(-4);
//     nums.push_back(3);
//     nums.push_back(56);
//     nums.push_back(-15);
//     nums.push_back(34);
//     nums.push_back(0);
//     nums.push_back(-14);
//     nums.push_back(4);
//     int result = maxConSubSum(nums);
//     cout<<"result: "<<result<<endl;
//     return 0;
// }


