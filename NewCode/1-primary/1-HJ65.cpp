/*
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！

数据范围：字符串长度 1≤length≤300 
进阶：时间复杂度：O(n^3) ，空间复杂度：O(n) 

输入描述：输入两个字符串
输出描述：返回重复出现的字符

示例1
输入：
    abcdefghijklmnop
    abcsafjklmnopqrstuvw
输出：
	jklmnop
*/
#include <iostream>
using namespace std;

int countStr(string str1, string str2) {
    int n = min(str1.size(), str2.size());
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(str1[i] != str2[i])  return sum;
        else if(str1[i] == str2[i]) sum++;
    } 
    return sum;
}

string getMaxStr(string str1, string str2) {
    string subStr;
    cout << str1 << "  " << str2 << endl;
    if(str1.size() > str2.size()) {
        swap(str1, str2);
        // string tmp = str1;
        // str1 = str2;
        // str2 = str1;
    }
    cout << str1 << "  " << str2 << endl;
    int m = str1.size();
    int n = str2.size();
    int len = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            len = countStr(str1.substr(i), str2.substr(j));
            subStr = subStr.size() < len ? str1.substr(i, len) : subStr;
            // cout << subStr << "  ";
        }
            // cout << endl;
    }
    return subStr;
    // return str2.substr(index, num);
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    cout << getMaxStr(str1, str2) << endl;
    return 0;
}