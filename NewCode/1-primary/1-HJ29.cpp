/*
对输入的字符串进行加解密，并输出。
加密方法为：
当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
其他字符不做变化。

解密方法为加密的逆过程。
数据范围：输入的两个字符串长度满足 1≤n≤1000，保证输入的字符串都是只由大小写字母或者数字组成
输入描述：
第一行输入一串要加密的密码
第二行输入一串加过密的密码

输出描述：
第一行输出加密后的字符
第二行输出解密后的字符

示例1
输入：
    abcdefg
    BCDEFGH
输出：
    BCDEFGH
    abcdefg
*/
#include <iostream>
using namespace std;

int getType(char ch) {
    if(ch >= '0' && ch <= '9')  return 0;
    if(ch >= 'a' && ch <= 'z')  return 1;
    if(ch >= 'A' && ch <= 'Z')  return 2;
    return 3;
}

void encodeStr(string str) {
// 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写
// 如字母a时则替换为B；字母Z时则替换为a；
// 当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0
    auto iter = str.begin();
    while (iter != str.end()) {
        char ch = *iter;
        switch (getType(ch)) {
            case 0: *iter = (ch - '0' + 1) % 10 + '0';  break;
            case 1: *iter = (ch - 'a' + 1) % 26 + 'A';  break;
            case 2: *iter = (ch - 'A' + 1) % 26 + 'a';  break;
        }
        iter++;
    }
    cout << str << endl;    
}

void decodeStr(string str) {
    auto iter = str.begin();
    while (iter != str.end()) {
        char ch = *iter;
        switch (getType(ch)) {
            case 0: *iter = (ch - '0' + 10 - 1) % 10 + '0';    break;
            case 1: *iter = (ch - 'a' + 26 - 1) % 26 + 'A';    break;
            case 2: *iter = (ch - 'A' + 26 - 1) % 26 + 'a';    break;
        }
        iter++;
    }
    cout << str << endl;
}

int main() {
    string str;
    cin >> str;
    encodeStr(str);
    cin >> str;
    decodeStr(str);
    return 0;
}