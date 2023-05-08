/*
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001

数据范围：0≤n≤2^30−1

输入描述：
输入一个int整数
输出描述：
将这个整数以字符串的形式逆序输出

示例1
输入：
	1516000
输出：
	0006151
示例2
输入：
	0
输出：
	0
*/
#include <iostream>
using namespace std;
#include <algorithm>
int main() {
    int n;
    cin >> n;
    string str = to_string(n);
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}