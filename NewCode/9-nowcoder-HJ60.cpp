/*
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。

数据范围：输入的数据满足4≤n≤1000 
输入描述：输入一个大于2的偶数
输出描述：从小到大输出两个素数
示例1
输入：
	20
输出：
    7
    13
示例2
输入：
	4
输出：
    2
    2
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
    for(int i = 2; i < n/2; i++)
        if(n%i == 0)    return false;
    return true;
}

void getPrimeCouple(int n) {
    int a = n/2;
    int b;
    while(a) {
        b = n - a;
        if(!isPrime(a)){
            a--;
            continue;
        }
        if(isPrime(b))  break;
        a--;
    }
    cout << a << endl;
    cout << b << endl;
}

int main() {
    int n;
    cin >> n;
    getPrimeCouple(n);
    return 0;
}
