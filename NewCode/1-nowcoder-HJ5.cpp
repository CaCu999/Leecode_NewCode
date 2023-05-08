/*
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在 1≤n≤2^{31}-1

输入描述：
输入一个十六进制的数值字符串。

输出描述：
输出该数值的十进制字符串。不同组的测试用例用\n隔开。

示例1
输入：0xAA
输出：170
*/
#include<iostream>
using namespace std;
#include <string>
int getHex(char ch) {
    int num;
    if (ch >= '0' && ch <= '9')       num = ch - '0';
    else if (ch == 'A' || ch == 'a')  num = 10;
    else if (ch == 'B' || ch == 'b')  num = 11;
    else if (ch == 'C' || ch == 'c')  num = 12;
    else if (ch == 'D' || ch == 'd')  num = 13;
    else if (ch == 'E' || ch == 'e')  num = 14;
    else if (ch == 'F' || ch == 'f')  num = 15;
    return num;
}

int change2Hex(string str) {
    char ch;
    int tmp,num = 0;
    for(int i = 2; i < str.size(); i++) {
        ch = str[i];
        tmp = getHex(ch);
        printf("getHex  %d\n",tmp);
        num = num << 4;
        printf("<<4  %d\n",ch,num);
        num = num | tmp;
        printf("ch %c     num %d\n",ch,num);
    }
    return 0;
}

int main() {
    string str;
    while (cin>>str) {
        cout << "   ------ >>>>  " << str << endl;
        change2Hex(str);
    }
    return 0;
}