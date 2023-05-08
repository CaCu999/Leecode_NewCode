/*
给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。

注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
数据范围：字符串长度：1≤s≤150 
进阶：时间复杂度：O(n^3) ，空间复杂度：O(n) 

输入描述：
输入两个只包含小写字母的字符串
输出描述：
输出一个整数，代表最大公共子串的长度

示例1
输入：
    asdfas
    werasdfaswer
输出：
	6
*/
#include <iostream>
using namespace std;

int getCommonStr(string str1, string str2) {
    if(str1.size() > str2.size())   swap(str1, str2);
    int maxVal = 0;
    for(int i = 0; i < str1.size(); i++) {
        char ch = str1[i];
        string cpstr = str1.substr(i);
        int j = str2.find_first_of(ch);
        for(; j < str2.size();) {
            for(int k = cpstr.size(); k > maxVal; k--) {
                if(str2.size() - j < k) k = str2.size() - j;
                if(cpstr.substr(0,k) == str2.substr(j,k))   maxVal = max(maxVal, k);
            }
            int tmp = str2.substr(j+1).find_first_of(ch);
            // printf("%c  %s  %d tmp==-1 %d  %d\n",ch, str2.substr(j+1).c_str(), j, (tmp == -1),tmp);
            if(tmp == -1)   break;
            j = tmp + j + 1;
            // system("pause");
        }        
    }
    cout << str1 << endl;
    cout << str2 << endl;
    return maxVal;
}

int main() {
    string str1,str2;
    // cin >> str1 >> str2;
    str1 = "aabbbbbababbabaaaba";
    str2 = "bababbbbbbbabbaabbabbabbbbabbbbbbbaaababababbbbaabaabababbabbababbaaabbbabbabbbaab";
    int res = getCommonStr(str1, str2);
    cout << res << endl;
    return 0;
}