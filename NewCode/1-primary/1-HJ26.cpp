/*
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
如，输入： Type 输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
如，输入： BabA 输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。
如，输入： By?e 输出： Be?y
数据范围：输入的字符串长度满足1≤n≤1000 

输入描述：输入字符串
输出描述：输出字符串
示例1
输入：
	A Famous Saying: Much Ado About Nothing (2012/8).
输出：
	A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

struct Letter {
    char val;
    int index;
    Letter(char ch, int i): val(ch), index(i){}
};

bool isLetter(char ch) {
    int n = ch - 'a';
    if (n >= 0 && n < 26)   return true;
    n = ch - 'A';
    if (n >= 0 && n < 26)   return true;
    return false;
}

char chang2Small(char ch) {
    int n = ch - 'A';
    if(n >=0 && n < 26) return n + 'a';
    return ch;
}

string getOrderedStr(string str) {
    vector<Letter> resChs;
    for(int i = 0; i < str.size(); i++) {
        if(isLetter(str[i])) {
            Letter ch(str[i], i);
            resChs.push_back(ch);
        }
    }
    sort(resChs.begin(), resChs.end(),[](Letter a, Letter b){
        char cha = chang2Small(a.val);
        char chb = chang2Small(b.val);
        if(cha == chb)
            return a.index < b.index;
        return cha < chb;
    });
    auto iter = resChs.begin();
    for(int i = 0; i < str.size(); i++) {
        if(isLetter(str[i]))    str[i] = (*iter++).val;
    }
    cout << str << endl;
    return str;
}

int main() {
    string str;
    string s;
    while(cin >> s) {
        str += " " + s;
        if(getchar() == '\n')   break;
    }
    getOrderedStr(str.substr(1));
    return 0;
}