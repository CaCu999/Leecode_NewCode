#include <iostream>
#include <algorithm>
using namespace std;

/*
24
6
8
3
12
7
9
7
*/
int main() {
    int n,v;
    // cin >> v >> n;
    v = 24;
    n = 6;
    int th[n+1] = {0,8,3,12,7,9,7};
    // for(int i = 0; i < n; i++) {
    //     cin >> th[i];
    // }
    for(int i = 1; i <= n; i++) {
        cout << th[i] << "  ";
    }
    cout << endl;
    int dp[v+1];
    for(int i = 0; i <= v; i++) {
        dp[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = v; j >= 0; j--) {
            if(j >= th[i]) {
                dp[j] = j - min((j - dp[j]),(j - dp[j - th[i]] - th[i]));
            }
            // printf("dp[%d]  %d\t",j,dp[j]);
            printf("%d\t",dp[j]);
        }
        cout << endl;
    }
    cout << v - dp[v] << endl;
    return 0;
}