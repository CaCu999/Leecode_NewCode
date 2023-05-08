#include <iostream>
using namespace std;

int fib1(int x) {
    if(1 == x || 2 == x) {
        return 1;
    }
    return fib1(x - 1) + fib1(x - 2);
}

int fib(int x) {
    int *dp = new int[x+1]();
    dp[1] = 1;
    dp[2] = 1;
    if(x <= 2)
        return dp[x];
    for(int i = 3; i <= x; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[x];
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}