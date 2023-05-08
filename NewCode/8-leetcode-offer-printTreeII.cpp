/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 

例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
提示：
节点总数 <= 1000
*/
#include <iostream>
using namespace std;
#include "../DataStructure/tree.h"

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int depth) {
        if (!root)   return;
        if (depth >= res.size())  res.push_back({});
        res[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right,depth + 1);
    }
};

int main() {
    vector<int> nums = {3,9,20,-1,-1,15,7};
    Solution sol;
    TreeNode *root = init(nums);
    vector<vector<int>> res;
    res = sol.levelOrder(root);
    for (auto ls:res) {
        for (auto x:ls)
            printf("%d  ",x);
        printf("\n");
    }
    return 0;
}