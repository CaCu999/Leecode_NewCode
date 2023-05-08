/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：
输入：n = 1, k = 1
输出：[[1]] 
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

class Solution {
    vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;        
    }
    void dfs(int cur, int n, int k) {
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = cur; i <= n - k + 1; i++) {
            tmp.push_back(i);
            dfs(i+1, n , k - 1);
            tmp.pop_back();
        }
    }
};

int main() {
    int n,k;
    cin >> n >> k;
    cout << n << "   " << k << endl;
    Solution sol;
    vector<vector<int>> res;
    res = sol.combine(n,k);
    for(auto vec:res) {
        for(auto n:vec) 
            printf("%d  ",n);
        printf("\n");
    }
    return 0;
}