/*
密码要求:
1.长度超过8位
2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）

数据范围：输入的字符串长度满足 1≤n≤100 
输入描述：
一组字符串。

输出描述：
如果符合要求输出：OK，否则输出NG

示例1
输入：
    021Abc9000
    021Abc9Abc1
    021ABC9000
    021$bc9000
输出：
    OK
    NG
    NG
    OK
*/
#include <iostream>
using namespace std;
#include <map>

bool isRight(string str) {
    int n = str.length();
    if (n < 8 || n > 100)       return false;
    map<string, int> strs;
    int isSmallLetter = 0;
    int isLargeLetter = 0;
    int isNum = 0;
    int isOther = 0;
    string tmp = "";
    for(int i = 0; i < n; i++) {
        char ch = str[i];
        cout << ch << endl;
        printf("%d  %d   %d\n",i+1,i+2,n);
        if (i + 1 < n && i + 2 < n) {
            tmp.clear();
            tmp.push_back(str[i]);
            tmp.push_back(str[i+1]);
            tmp.push_back(str[i+2]);
            printf("%c%c%c  ",str[i],str[i+1],str[i+2]);
            cout << tmp << endl;
            if(strs[tmp])   return false;
            strs[tmp]++;
        }
        if ((ch - 'a') >= 0 && (ch - 'a') <= 26)        isSmallLetter = 1;
        else if ((ch - 'A') >= 0 && (ch - 'A') <= 26)   isLargeLetter = 1;
        else if ((ch - '0') >= 0 && (ch - '0') <= 9)    isNum = 1;
        else    isOther = 1;
    }
    if((isSmallLetter + isLargeLetter + isNum + isOther) < 3)   return false;
    return true;
}

int main() {
    string str;
    while(cin >> str) {
        bool res = isRight(str);
        if(res) cout << "OK" << endl;
        else    cout << "NG" << endl;
    }
    return 0;
}