/*
输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。
数据范围：输入的字符串长度满足 1≤n≤1000 

输入描述：输入一行字符串，可以有空格
输出描述：统计其中英文字符，空格字符，数字字符，其他字符的个数

示例1
输入：
	1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][
输出：
    26
    3
    10
    12
*/
#include <iostream>
using namespace std;

void countChar(string str, int nums[]) {
    for(int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')     nums[0]++;
        else if (str[i] >= '0' && str[i] <= '9')    nums[2]++;
        else    nums[3]++;
    }
}

int main() {
    string str;
    int nums[4] = {0, 0, 0, 0};    
    while(cin >> str) {
        countChar(str, nums);
        if(getchar() == '\n')   break;
        nums[1]++;
    }
    for(int i = 0; i < 4; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}