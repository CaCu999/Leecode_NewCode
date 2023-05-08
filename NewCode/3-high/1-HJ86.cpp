/*
求一个int类型数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

数据范围：数据组数：1≤t≤5，1≤n≤500000 
进阶：时间复杂度：O(logn)，空间复杂度：O(1)

输入描述：输入一个int类型数字
输出描述：输出转成二进制之后连续1的个数

示例1
输入：
	200
输出：
	2
说明：200的二进制表示是11001000，最多有2个连续的1。
*/
#include <iostream>
using namespace std;

int getNum(int n) {
    int res = 0;
    int cur = 0;
    bool isChange = false;
    while (n) {
        if(n%2) {
            if(!isChange) {
                cur = 0;
                isChange = true;
            }
            cur++;
        } else if(!(n%2) && isChange) {
            isChange = false;
            res = max(cur, res);
        }
        n = n / 2;
    }
    res = max(cur, res);
    return res;    
}

int main() {
    int n;
    cin >> n;
    cout << getNum(n) << endl;
    return 0;
}