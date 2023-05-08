#include <iostream>
#include <algorithm>
using namespace std;
/*
3 5		//n组，容量v
2		//i组有s件物品
1 2
2 4
1
3 4
1
4 5
*/

void bag1() {
    int n,m;
    cin >> n >> m;
    int v[n+1][201],w[n+1][201];
    int s[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        v[i][0] = 0;
        w[i][0] = 0;
        for(int j = 1;j <= s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    int dp[m+1];
    for(int i = 0; i <= m; i++)
        dp[i] =0;
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
            for(int k = 0;k <= s[i]; k++) {
                if(j >= v[i][k])
                    dp[j] = max(dp[j],dp[j-v[i][k]] + w[i][k]);
                printf("v[%d][%d] %d w[%d][%d] %d dp[%d] %d \n",i,k,v[i][k],i,k,w[i][k],j,dp[j]);
            }
            printf("   ====> dp[%d]  %d   \n",j,dp[j]);
        }
    }
}

void bag2() {
    int n,m;
    cin >> n >> m;
    int v[n+1][201],w[n+1][201];
    int s[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        v[i][0] = 0;
        w[i][0] = 0;
        for(int j = 1;j <= s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    int dp[n+1][m+1];
    for(int i = 0; i <= m; i++)
        dp[0][i] =0;
    for(int i = 0; i <= n; i++)
        dp[i][0] =0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            for(int k = 0;k <= s[i]; k++) {
                if(j >= v[i][k])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-v[i][k]] + w[i][k]);
                printf("v[%d][%d] %d w[%d][%d] %d dp[%d][%d] %d \n",i,k,v[i][k],i,k,w[i][k],i,j,dp[i][j]);
            }
            printf("   ====> dp[%d][%d]  %d   \n",i,j,dp[i][j]);
        }
    }
}

int main() {
    bag1();
    return 0;
}