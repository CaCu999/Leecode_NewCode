/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 

例如:
给定二叉树: [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [20,9],
  [15,7]
] 
*/
#include <iostream>
using namespace std;
#include "../DataStructure/tree.h"
#include <algorithm>

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        for(int i = 0; i < res.size(); i++) {
            if (i % 2 == 0) continue;
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth >= res.size())    res.push_back({});
        res[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    TreeNode *root = init(nums);
    Solution sol;
    vector<vector<int>> res = sol.levelOrder(root);
    for (auto ls:res) {
        for (auto x:ls)
            printf("%d  ",x);
        printf("\n");
    }
    return 0;
}