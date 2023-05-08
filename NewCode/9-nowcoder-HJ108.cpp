/*
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

数据范围：1≤a,b≤100000 
输入描述：输入两个正整数A和B。
输出描述：输出A和B的最小公倍数。
示例1
输入：
	5 7
输出：
	35
示例2
输入：
	2 4
输出：
	4
*/
#include <iostream>
using namespace std;

int getMaxFactor(int m, int n) {
    int res = min(m,n);
    while (res > 1) {
        if(m % res == 0 && n % res == 0)    break;
        res--;
    }
    return res;    
}

int getMinMultiple(int m, int n) {
    int k = getMaxFactor(m, n);
    return m*n/k;
}

int main() {
    int m;
    int n;
    cin >> m >> n;
    cout << getMinMultiple(m, n);
    return 0;
}
