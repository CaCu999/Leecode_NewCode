/*
对于长度为n的一个字符串A（仅包含数字，大小写英文字母），请设计一个高效算法，计算其中最长回文子串的长度。

数据范围：1≤n≤1000
要求：空间复杂度O(1)，时间复杂度O(n^2)
进阶:  空间复杂度O(n)，时间复杂度O(n)

示例1
输入：
	"ababc"
返回值：
	3
说明：
最长的回文子串为"aba"与"bab"，长度都为3

示例2
输入：
	"abbba"
返回值：
	5

示例3
输入：
	"b"
返回值：
	1
*/
#include <iostream>
using namespace std;
#include <algorithm>

class Solution {
public:
    int getLongestPalindrome(string str) {
        if(str.size() <= 1) return  str.size();
        int len = str.size();
        string revStr;
        while(len) {
            for(int i = 0; i <= str.size() - len; i++) {
                revStr.assign(str.substr(i,len));
                reverse(revStr.begin(),revStr.end());
                if(str.substr(i,len).compare(revStr) == 0)  return len;
            }
            len--;
        }
        return len;
    }
};

int main() {
    string str;
    cin >> str;
    Solution sol;
    cout << sol.getLongestPalindrome(str) << endl;
    return 0;
}
