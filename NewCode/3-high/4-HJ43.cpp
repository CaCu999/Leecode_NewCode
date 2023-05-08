/*
定义一个二维数组 N*M ，如 5 × 5 数组下所示：
int maze[5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的路线。入口点为[0,0],既第一格是可以走的路。
数据范围：2≤n,m≤10，输入的内容只包含 0≤val≤1 

输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1
输入：
    5 5
    0 1 0 0 0
    0 1 1 1 0
    0 0 0 0 0
    0 1 1 1 0
    0 0 0 1 0
输出：
    (0,0)
    (1,0)
    (2,0)
    (2,1)
    (2,2)
    (2,3)
    (2,4)
    (3,4)
    (4,4)
示例2
输入：
    5 5
    0 1 0 0 0
    0 1 0 1 0
    0 0 0 0 1
    0 1 1 1 0
    0 0 0 0 0
输出：
    (0,0)
    (1,0)
    (2,0)
    (3,0)
    (4,0)
    (4,1)
    (4,2)
    (4,3)
    (4,4)
说明：注意：不能斜着走！！   
*/
#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    int m,n;
    vector<vector<int>> nums;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> res;
public:
    Solution(vector<vector<int>> num, int m, int n):nums(num), m(m-1), n(n-1){}
    void dfs(int i, int j, vector<pair<int, int>> path) {
        pair<int, int>  loc = {i, j};
        if(i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() || nums[i][j]) return ;
        printf("cur loc: %d, %d [%d, %d]\n",i,j,nums.size(),nums[0].size());
        path.push_back(loc);
        nums[i][j] = 1;
        if(i == m && j == n)    res = path;
        for(int n = 0; n < dirs.size(); n++) {
            dfs(dirs[n][0] + i, dirs[n][1] + j, path);
        }
    }

    void getPath() {
        vector<pair<int, int>> path;
        dfs(0,0,path);
        for(auto p:res) {
            printf("(%d,%d)\n",p.first,p.second);
        }
    }
};

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n, 0));
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++)
            cin >> nums[i][j];
    }
    Solution sol(nums, m, n);
    sol.getPath();
    return 0;
}