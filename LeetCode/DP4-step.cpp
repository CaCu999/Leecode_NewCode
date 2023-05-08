#include <iostream>
#include <algorithm>
using namespace std;

void step(int *cost, int n) {
    int *dp = new int[n+1]();
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
    }
    cout << dp[n];
}

int main() {
    int n;
    cin >> n;
    int *cost = new int[n+1]();
    for(int i = 0; i <= n; i++) {
        cin >> cost[i];
    }
    cost[n] = 0;
    step(cost, n);
    return 0;
}