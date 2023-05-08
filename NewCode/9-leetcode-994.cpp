/*
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1

示例 1：
输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：
输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：
输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
*/
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int step = -1;
        queue<pair<int,int>>  que;
        bool isOnlyZero = true;
        for (auto ls:grid)
            for (auto x:ls)
                if (x) isOnlyZero = false;
        if(isOnlyZero)  return 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 2) que.emplace(i,j);
        while (!que.empty()) {
            int size = que.size();
            step++;
            while(size--) {
                auto [x, y] = que.front();
                que.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[nx].size() && grid[nx][ny] == 1) {
                        que.emplace(nx, ny);
                        grid[nx][ny] = 2;
                    }
                }
            }
        }
        for (auto ls:grid)
            for (auto x:ls)
                if (1 == x)
                    return -1;
        return step;
    }
};

int main() {
    vector<vector<int>> grid;
    grid.push_back({2,1,1});
    grid.push_back({0,1,1});
    grid.push_back({1,0,1});
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}