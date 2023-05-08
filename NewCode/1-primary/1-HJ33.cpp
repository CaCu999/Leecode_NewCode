/*
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001

组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。

数据范围：保证输入的是合法的 IP 序列

输入描述：
输入 
1 输入IP地址
2 输入10进制型的IP地址

输出描述：
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址

示例1
输入：
    10.0.3.193
    167969729
输出：
    167773121
    10.3.3.193
*/
#include <iostream>
using namespace std;
#include <algorithm>

string biStr(string str) {
    int n = atoi(str.c_str());
    str.clear();
    string tmp(8, '0');
    int i = 0;
    while(n) {
        tmp[i++] = '0' + n % 2;
        n = n / 2;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string biStr2IntStr(string str) {
    long long n = 0;
    for(int i = 0; i < str.size(); i++) {
        n = n << 1;
        n += (str[i] - '0');
    }
    str.clear();
    while(n) {
        str.push_back('0' + n % 10);
        n = n /10;
    }
    reverse(str.begin(), str.end());
    if(str.empty()) return "0";
    return str;
}

void str2BiStr(string str) {
    string tmp;
    int start = 0;
    string res;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] == '.') {
            tmp = str.substr(start, i - start);
            start = i + 1;
            res.append(biStr(tmp));
        } else if (i == str.size() - 1) {
            tmp = str.substr(start);
            res.append(biStr(tmp));
        }
    }
    res = biStr2IntStr(res);
    cout << atoll(res.c_str()) << endl;
}

void biStr2Str(string str) {
    long long n = atoll(str.c_str());
    string res(32, '0');
    int i = 0;
    while(n) {
        res[i++] = '0' + n % 2;
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    str.clear();
    for (int i = 0; i < 4; i++) {
        str.append(biStr2IntStr(res.substr(8 * i, 8)));
        if(i < 3)   str.push_back('.');
    }
    cout << str << endl;    
}

int main() {
    string str;
    cin >> str;
    str2BiStr(str);
    cin >> str;
    biStr2Str(str);
    return 0;
}