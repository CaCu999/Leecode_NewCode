/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

数据范围：1≤n≤40
要求：时间复杂度：O(n)O(n) ，空间复杂度： O(1)O(1)
示例1
输入：		2
返回值：	2
说明：
青蛙要跳上两级台阶有两种跳法，分别是：先跳一级，再跳一级或者直接跳两级。因此答案为2       
示例2
输入：		7
返回值：	21
*/
#include <iostream>
using namespace std;
int stepJump(int step) {
    int dp[step + 1] = {0};
    if(step <= 1)   return step;
    dp[1] = 1;
    dp[0] = 1;
    for(int i = 2; i <= step; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        printf("%d   ",dp[i]);
    }
    printf("\n");
    return dp[step];
}

int main() {
    int step = 7;
    cout << stepJump(step) << endl;
    return 0;
}