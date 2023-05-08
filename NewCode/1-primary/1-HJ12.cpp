/*
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述：
输入一行，为一个只包含小写字母的字符串。
输出描述：
输出该字符串反转后的字符串。

示例1
输入：
	abcd
输出：
	dcba
*/
#include <iostream>
using namespace std;
#include <algorithm>
int main() {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}