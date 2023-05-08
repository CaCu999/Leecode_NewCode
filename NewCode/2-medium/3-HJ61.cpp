/*
把m个同样的苹果放在n个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
注意：如果有7个苹果和3个盘子，（5，1，1）和（1，5，1）被视为是同一种分法。

数据范围：0≤m≤10 ，1≤n≤10 。

输入描述：输入两个int整数
输出描述：输出结果，int型

示例1
输入：7 3
输出：8
*/
#include <iostream>
using namespace std;
#include <vector>

int allRes(int apple, int plate) {
    // apple × plate
    vector<vector<int>> dp(apple + 1, vector<int>(plate + 1, 0));
    //0 apple
    for (int i = 0; i <= plate; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= apple; i++) {
        for (int j = 1; j <= plate; j++) {
            if(j > i)   dp[i][j] = dp[i][i];
            else        dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
        printf("%d:  ",i);
        for(int j = 0; j <= plate; j++)
        printf("%d\t", dp[i][j]);
        printf("\n");
    }   
    
    return dp[apple][plate];
}

int main() {
    int a,b;
    cin >> a >> b;
    int n = allRes(a, b);
    cout << n << endl;
    return 0;
}