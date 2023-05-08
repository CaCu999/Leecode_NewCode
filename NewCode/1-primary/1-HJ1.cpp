/*
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。

示例1
输入：
	hello nowcoder
输出：
	8
说明：
最后一个单词为nowcoder，长度为8 
*/
#include <iostream>
using namespace std;
int main() {
    string str;
    while(cin >> str) {
        cout << "string is : " << str << endl;
        if(getchar() == '\n')   break;
    }
    cout << str.size() << endl;
    return 0;
}