/*
找出字符串中第一个只出现一次的字符

数据范围：输入的字符串长度满足 1≤n≤1000 

输入描述：输入一个非空字符串
输出描述：输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入：
	asdfasdfo
输出：
	o
*/
#include <iostream>
using namespace std;
#include <map>

char getChar(string str) {
    map<char, int> chars;
    auto iter = str.begin();
    while(iter != str.end()) {
        chars[*iter]++;
        iter++;
    }
    iter = str.begin();
    while(iter != str.end()) {
        if(chars[*iter] == 1)    return *iter;
        iter++;
    }
    return '0';
}

int main() {
    string str;
    cin >> str;
    char ch = getChar(str);
    if(ch == '0')
        cout << "-1" << endl;
    else
        cout << ch << endl;
    return 0;
}