/*
根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。
进阶：时间复杂度：O(n) ，空间复杂度：O(1) 
输入描述：
输入一行，每行空格分割，分别是年，月，日

输出描述：输出是这一年的第几天
示例1
输入：
	2012 12 31
输出：
	366
示例2
输入：
	1982 3 4
输出：
	63
*/
#include <iostream>
using namespace std;
int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRound(int year) {
    if(year % 4 == 0 && year % 100 != 0)    return true;
    if(year % 400 == 0) return true;
    return false;
}
int getDays(int year, int month, int day) {
    int res = 0;
    for(int i = 0; i < month - 1; i++) {
        res += date[i];
    }
    if(month > 2)   res += isRound(year);
    res += day;
    return res;
}
int main() {
    int y,m,d;
    cin >> y >> m >> d;
    int res = getDays(y, m, d);
    cout << res << endl;
    return 0;
}