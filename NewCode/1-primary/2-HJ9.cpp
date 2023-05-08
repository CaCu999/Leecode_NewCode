/*
输入一个 int 型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
保证输入的整数最后一位不是 0 。

数据范围：1≤n≤10^8
  
输入描述：输入一个int型整数
输出描述：按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

示例1
输入：
	9876673
输出：
	37689
*/
#include <iostream>
using namespace std;
#include <algorithm>

int getNewInt(string str) {
    int nums[10] = {0};
    string res = "";
    int n = 0;
    reverse(str.begin(), str.end());
    for(auto ch: str) {
        n = ch - '0';
        if(!nums[n]++)  res.push_back(ch);
    }
    n = atoi(res.c_str());
    return n;
}

int main() {
    string str;
    string res;
    cin >> str;
    cout << getNewInt(str) << endl;
    return 0;
}