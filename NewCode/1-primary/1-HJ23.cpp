/*
实现删除字符串中出现次数最少的字符，若出现次数最少的字符有多个，则把出现次数最少的字符都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

数据范围：输入的字符串长度满足 1≤n≤20  ，保证输入的字符串中仅出现小写字母
输入描述：
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。

输出描述：
删除字符串中出现次数最少的字符后的字符串。

示例1
输入：
	aabcddd
输出：
	aaddd
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

string returnChars(string str) {
    vector<pair<char, int>> chars;
    for(int i = 0; i < 26; i++)
        chars.emplace_back('a'+i,0);
    for(int i = 0; i < str.size(); i++) {
        chars[str[i] - 'a'].second++;
    }
    for(auto p:chars)
        printf("%c - %d\t", p.first, p.second);
    printf("\n");
    sort(chars.begin(), chars.end(), [](pair<char, int> a, pair<char, int> b){return a.second < b.second;});
    int min = str.size();
    map<char, int> delChar;
    for(auto p:chars) {
        if(!p.second)   continue;
        if(p.second <= min) {
            min = p.second;
            delChar[p.first]++;
        } else {
            break;
        }
    }
    string resStr = "";
    for(int i = 0; i < str.size(); i++)
        if(delChar.find(str[i]) == delChar.end()) 
            resStr.push_back(str[i]);
    str = resStr;
    cout << str << endl;
    return str;
}

int main() {
    char ch ;
    string str;
    cin >> str;
    returnChars(str);
    return 0;
}