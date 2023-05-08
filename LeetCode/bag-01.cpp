#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int v;
    cin >> v;
    int dp[n+1][v+1];
    int vv[n+1],ww[n+1];
    for(int i = 1; i <= n ; i++) {
        cin >> vv[i] >> ww[i];
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= v ; i++) {
        dp[0][i] = 0;
        printf("dp[%d][%d] = %d \n",0,i, dp[0][i]);
    }
    for(int i = 0 ; i <= n ; i++) {
        printf("dp[%d][%d] = %d \n",0,i, dp[i][0]);
    }
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= v ; j++) {
            printf("\n\n\n");
            if(j < vv[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - vv[i]] + ww[i]);
            printf("dp[i-1][j]  %d  \ndp[i-1][j - vv[i]]  %d    vv[i]  %d     ww[i]  %d     dp[i-1][j - vv[i]] + ww[i] %d    j - vv[i]  %d\n",
            dp[i-1][j],dp[i-1][j - vv[i]],vv[i],ww[i] ,(dp[i-1][j - vv[i]] + ww[i]),(j - vv[i]));
            }
            printf("dp[%d][%d]  %d    \n",i,j,dp[i][j]);
        }
    }
    cout << dp[n][v] << endl;
    /*
4 5
1 2
2 4
3 4
4 5
    */

    return 0;
}