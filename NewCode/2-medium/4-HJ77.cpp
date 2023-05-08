/*
输出 1到n之间 的与 7 有关数字的个数。
一个数与7有关是指这个数是 7 的倍数，或者是包含 7 的数字（如 17 ，27 ，37 ... 70 ，71 ，72 ，73...）

数据范围： 1≤n≤30000 
输入描述：一个正整数 n 。( n 不大于 30000 )

输出描述： 一个整数，表示1到n之间的与7有关的数字个数。

示例1
输入：
	20
输出：
	3
说明：
输入20，1到20之间有关的数字包括7,14,17共3个
*/
#include <iostream>
using namespace std;

bool isContain7 (int n) {
    int num = 0;
    while(n) {
        num = n % 10;
        if(num == 7)    return true;
        n = n / 10;
    }
    return false;
}

int getNumOf7 (int n) {
    int num = 0;
    for(int i = 1; i <= n; i++) {
        if (i % 7 == 0)   num++;
        else if (isContain7(i)) num++;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    cout << getNumOf7(n) << endl;
    return 0;
}