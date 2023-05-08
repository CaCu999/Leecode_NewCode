/*
题目标题：将两个整型数组按照升序合并，并且过滤掉重复数组元素。
输出时相邻两数之间没有空格。

输入描述：
输入说明，按下列顺序输入：
1 输入第一个数组的个数
2 输入第一个数组的数值
3 输入第二个数组的个数
4 输入第二个数组的数值

输出描述：输出合并之后的数组

示例1
输入：
    3
    1 2 5
    4
    -1 0 3 2
输出：
	-101235
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void mergevector(vector<int> num1, vector<int> num2) {
    // sort(num1.begin(), num1.end());
    // sort(num2.begin(), num2.end());
    vector<int> num(num1.size()+num2.size());
    merge(num1.begin(), num1.end(), num2.begin(), num2.end(), num.begin());
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);  
    }
    // int i = 0, j = 0;
    int cur = num[0];
    printf("%d", cur);
    for(int i = 1; i < num.size(); i++) {
        if(cur != num[i]) {
            cur = num[i];
            printf("%d", cur);
        }
    }
    printf("\n");    
}

int main() {
    int n;
    cin >> n;
    vector<int> num1(n,0);
    for(int i = 0; i < n; i++)
        cin >> num1[i];
    cin >> n;
    vector<int> num2(n,0);
    for(int i = 0; i < n; i++)
        cin >> num2[i];
    mergevector(num1, num2);
    return 0;
}