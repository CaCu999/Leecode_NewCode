/*
输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；
长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。

输入描述：
连续输入字符串(每个字符串长度小于等于100)
输出描述：
依次输出所有分割后的长度为8的新字符串

示例1
输入：
	abc
输出：
	abc00000
*/
#include <iostream>
using namespace std;

void showStrs(string str) {
    int i = 0;
    int len = 0;
    while(i < str.size()) {
        len = str.size() - i;
        if(len < 8) {
            cout << str.substr(i);
            len = 8 - len;
            break;
        } else {
            cout << str.substr(i,8) << endl;
            i = i + 8;
        }
    }
    if(len == 8)    return;
    while (len--){
        printf("%c",'0');
    }
    printf("\n");
    
}

int main() {
    string str;
    cin >> str;
    showStrs(str);
    return 0;
}