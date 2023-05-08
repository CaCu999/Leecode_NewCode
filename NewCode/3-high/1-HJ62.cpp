/*
描述
输入一个正整数，计算它在二进制下的1的个数。
注意多组输入输出！！！！！！

数据范围： 1≤n≤2^31−1 
输入描述：输入一个整数

输出描述：计算整数二进制中1的个数

示例1
输入：
	5
输出：
	2
说明：5的二进制表示是101，有2个1   
示例2
输入：
	0
输出：
	0
*/
#include <iostream>
using namespace std;

int getNum(int n) {
    int res = 0;
    while (n) {
        if(n%2 & 1) res++;
        n = n / 2;
    }
    return res;    
}

int main() {
    int n;
    while(cin >> n) {
        cout << getNum(n) << endl;
    }
    return 0;
}