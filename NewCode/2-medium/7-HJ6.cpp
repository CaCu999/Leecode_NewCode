/*
功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）

数据范围：1≤n≤2×10^9+14 
输入描述：输入一个整数

输出描述：
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。

示例1
输入：180
输出：2 2 3 3 5
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

bool isPrime(int n) {
    // cout << n << endl;
    for(int i = 2; i * i <= n; i++) {
        // cout << i << " " << n%i << endl;
        if(!(n%i)) return false;
        }
    return true;
}

void allSum(int n) {
    vector<int> num;
    for(int i = 2; i * i <= n; i++) {
        printf("n %d i %d\n",n,i);
        if(isPrime(n)) {
            num.push_back(n);
            break;
        }
        cout << i << " " << n%i << endl;
        if(isPrime(i) && !(n % i)) {
            num.push_back(i);
            n = n / i;
            i = 1;
        }
    }
    sort(num.begin(), num.end());
    if(!num.empty()) printf("%d",num[0]);
    for(int i =1; i < num.size(); i++)
        printf(" %d", num[i]);
}

int main() {
    int n = 25;
    // cin >> n;
    allSum(n);
    return 0;
}