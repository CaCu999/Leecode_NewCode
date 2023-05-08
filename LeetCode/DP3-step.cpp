#include <iostream>
#include <math.h>
using namespace std;
void step(int n) {
    int *dp = new int[n+1]();
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = 2 * dp[i-1];
    }
    cout << dp[n];
}
int main() {
    int n;
    cin >> n;
    step(n);
    return 0;
}