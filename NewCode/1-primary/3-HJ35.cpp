/*
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

例如，当输入5时，应该输出的三角形为：
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11

输入描述：输入正整数N（N不大于100）
输出描述：输出一个N行的蛇形矩阵。

示例1
输入：
	4
输出：
    1 3 6 10
    2 5 9
    4 8
    7
*/
#include <iostream>
using namespace std;
#include <vector>

int getSum(int n) {
    return n = n * (n + 1) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n,vector<int>(0));
    for(int i = 0; i < n; i++) {
        nums[0].push_back(getSum(i + 1));
    }
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 1; j < nums[i-1].size(); j++) {
            nums[i].push_back(nums[i-1][j]-1);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++)
            printf("%d ",nums[i][j]);
        printf("\n");
    }    
    return 0;
}