/*
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

数据范围：字符串长度 0≤n≤10000
要求：空间复杂度O(n)，时间复杂度 O(n)
示例1

输入：
	"["
返回值：
	false

示例2
输入：
	"[]"
返回值：
	true
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        if(str.size() % 2 != 0) return false;
        char ch;
        string res;
        for(int i = 0; i < str.size(); i++) {
            ch = str[i];
            switch (ch) {
            case '(' :
            case '[' : 
            case '{' : 
                res.push_back(ch);
                break;
            case ')' :
                if(res.back() != '(')   return false;
                else {
                    res.pop_back();
                    break;
                }
            case ']' :
                if(res.back() != '[')   return false;
                else {
                    res.pop_back();
                    break;
                }
            case '}' :
                if(res.back() != '{')   return false;
                else {
                    res.pop_back();
                    break;
                }
            }
        }
        if(res.size())  return false;
        return true;
    }
};

int main() {
    Solution sol;
    string str;
    cin >> str;
    bool res = sol.isValid(str);
    if(res) cout << "true" << endl;
    else    cout << "false" << endl;
    return 0;
}