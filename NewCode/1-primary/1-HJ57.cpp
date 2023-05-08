/*
输入两个用字符串 str 表示的整数，求它们所表示的数之和。

数据范围：1≤len(str)≤10000 
输入描述：输入两个字符串。保证字符串只含有'0'~'9'字符
输出描述：输出求和后的结果

示例1
输入：
    9876543210
    1234567890
输出：
	11111111100
*/
#include <iostream>
using namespace std;
#include <algorithm>

string getNum(string str1, string str2) {
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int n = min(str1.size(), str2.size());
    int c = 0;
    int a,b;
    for(int i = 0; i < n; i++) {
        a = str1[i] - '0';
        b = str2[i] - '0';
        str1[i] = (a + b + c) % 10 + '0';
        c = (a + b + c) / 10;
    }
    printf("str1.len: %d  str2.len: %d  n: %d  c: %d\n", 
                str1.size(), str2.size(), n, c);
    if(str1.size() > n) {
        for(int i = n; i < str1.size(); i++) {
            a = str1[i] - '0';
            str1[i] = (a + c) % 10 + '0';
            c = (a + c) / 10;
        }
    } else if(str2.size() > n) {
        for(int i = n; i < str2.size(); i++) {
            a = str2[i] - '0';
            str1.push_back((a + c) % 10 + '0');
            c = (a + c) / 10;
        }
    }
    if(c)   str1.push_back(c + '0');
    reverse(str1.begin(), str1.end());
    cout << str1 << endl;
    return str1;
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    getNum(str1, str2);
    return 0;
}