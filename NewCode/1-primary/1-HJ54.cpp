/*
给定一个字符串描述的算术表达式，计算出结果值。

输入字符串长度不超过 100 ，合法的字符包括 ”+, -, *, /, (, )” ， ”0-9” 。

数据范围：运算过程中和最终结果均满足∣val∣≤2^31−1 ，即只进行整型运算，确保输入的表达式合法
输入描述：输入算术表达式
输出描述：计算出结果值

示例1
输入：
	400+5
输出：
	405
*/
#include <iostream>
using namespace std;
#include <stack>

int getType(char ch) {
    if(ch >= '0' && ch <= '9')  return 0;
    if(ch == '+' || ch == '-')  return 1;
    if(ch == '*' || ch == '/')  return 2;
    if(ch == '(')   return 3;
    if(ch == ')')   return 4;
    return -1;
}

int oper(int a, int b, char ch) {
    switch (ch) {
        case '+':   return  a + b;
        case '-':   return  a - b;
        case '*':   return  a * b;
        case '/':   return  a / b;
    }
    return 0;
}

template<typename T>
T getTop(stack<T> &s) {
    T t = s.top();
    s.pop();
    return t;
}

void cal(stack<int> &nums, stack<char> &ops) {
    if(nums.size() < 2 || ops.empty())  return;
    int a = getTop(nums);
    int b = getTop(nums);
    char ch = getTop(ops);
    a = oper(b, a, ch);
    nums.push(a); 
}

int getRes(string str) {
    stack<int> nums;
    stack<char> ops;
    int start = 0;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(i == str.size() - 1 && !getType(ch))
            nums.push(atoi(str.substr(start, i - start + 1).c_str()));
        if(!getType(ch))    continue;
        if(start != i)  nums.push(atoi(str.substr(start, i - start).c_str()));
        else if(ch == '-' && (i == 0 || str[i-1] == '(')) nums.push(0);
        int n = getType(ch);
        start = i + 1;
        if(n == 1) {
            while (!ops.empty() && getType(ops.top()) <= 2)
                cal(nums, ops);
        } else if (n == 2) {
            while (!ops.empty() && getType(ops.top()) == 2)
                cal(nums, ops);
        } else if (n == 4) {
            while (ops.top() != '(')
                cal(nums, ops);
            ops.pop();
            continue;         
        }        
        ops.push(ch);
    }
    while(!ops.empty())
        cal(nums, ops);
    cout << nums.top() << endl;
    return nums.top();
}

int main() {
    string str;
    cin >> str;
    getRes(str);
    return 0;
}