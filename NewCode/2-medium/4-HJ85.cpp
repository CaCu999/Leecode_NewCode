/*
给定一个仅包含小写字母的字符串，求它的最长回文子串的长度。
所谓回文串，指左右对称的字符串。
所谓子串，指一个字符串删掉其部分前缀和后缀（也可以不删）的字符串
数据范围：字符串长度 1≤s≤350 
进阶：时间复杂度：O(n) ，空间复杂度：O(n)

输入描述：
输入一个仅包含小写字母的字符串
输出描述：
返回最长回文子串的长度

示例1
输入：
	cdabbacc
输出：
	4

说明：
abba为最长的回文子串
*/
#include <iostream>
using namespace std;
#include <algorithm>

int getStrLen(string str) {
    string subStr;
    string revStr;
    for (int len = str.size(); len > 0; len--) {
        for (int index = 0; index < str.size(); index++) {
            if(len + index > str.size())  break;
            subStr = str.substr(index, len);
            revStr = subStr;
            reverse(revStr.begin(), revStr.end());
            if(!subStr.compare(revStr))  {
                cout << subStr << "  " << revStr << "  res:  " << subStr.compare(revStr) << endl;
                return subStr.size();
            }
        }
    }
    return 0;    
}

int main() {
    string str;
    cin >> str;
    cout << getStrLen(str) << endl;
    return 0;
}