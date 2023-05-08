/*
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围：1≤n≤1000 
输入描述：
第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。
输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母）

示例1
输入：
	ABCabc
	A
输出：
	2
*/
#include <iostream>
using namespace std;
#include <map>

int getLetterNum(string str, char ch) {
    if(ch <= 'Z')   ch = ch - 'A' + 'a';
    map<char, int> chars;
    for(auto c: str) {
        if (c <= 'Z') c = c - 'A' + 'a';
        chars[c]++;
    }
    return chars[ch];
}

int main() {
    string str,tmp;
    while(cin >> tmp) {
        str += tmp;
        if(getchar() == '\n')   break;
    }
    cout << str << endl;
    char ch;
    cin >> ch;
    cout << getLetterNum(str, ch) << endl;
    return 0;
}