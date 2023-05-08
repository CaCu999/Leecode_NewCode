#include <iostream>
#include <algorithm>
using namespace std;

void bag2() {
    //物品种数和背包容积
    int n,m;
    cin >> n >> m;
    int v[n+1],w[n+1];
    int dp[n+1][m+1];
    //体积和价值
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    //初始化状态数组
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) { 
            dp[i][j] = dp[i-1][j];
            if(j >= v[i])
                dp[i][j] = max(dp[i][j],dp[i][j - v[i]] + w[i]);
            printf("dp[%d][%d]  %d\t",i,j,dp[i][j]);
            /*
dp[1][0]  0     dp[1][1]  2     dp[1][2]  4     dp[1][3]  6     dp[1][4]  8     dp[1][5]  10
dp[2][0]  0     dp[2][1]  2     dp[2][2]  4     dp[2][3]  6     dp[2][4]  8     dp[2][5]  10
dp[3][0]  0     dp[3][1]  2     dp[3][2]  4     dp[3][3]  6     dp[3][4]  8     dp[3][5]  10
dp[4][0]  0     dp[4][1]  2     dp[4][2]  4     dp[4][3]  6     dp[4][4]  8     dp[4][5]  10
            */
        }
    }
    cout << dp[n][m] << endl;
}

void bag1() {
    int n,m;
    cin >> n >> m;
    int dp[m+1];
    for(int i = 0; i <= m; i++)
        dp[i] = 0;
    int v,w;
    for(int i = 1; i <= n; i++) {
        cin >> v >> w;
        for(int j = v ; j <= m; j++) {
            dp[j] = max(dp[j],dp[j - v] + w);
            printf("dp[%d]  %d\t",j,dp[j]);
        }
        cout<<endl;
    }
    cout << dp[m] << endl;
}

/*
4 5
1 2
2 4
3 4
4 5
    */
int main() {
    bag1();
    return 0;
}