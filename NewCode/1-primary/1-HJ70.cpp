/*
矩阵乘法的运算量与矩阵乘法的顺序强相关。
例如：
A是一个50×10的矩阵，B是10×20的矩阵，C是20×5的矩阵
计算A*B*C有两种顺序：((AB)C)或者(A(BC))，前者需要计算15000次乘法，后者只需要3500次。
编写程序计算不同的计算顺序需要进行的乘法次数。

数据范围：矩阵个数：1≤n≤15 ，行列数：1≤row_i ,col_i ≤100 ，保证给出的字符串表示的计算顺序唯一。
进阶：时间复杂度：O(n) ，空间复杂度：O(n) 

输入描述：
输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则
计算的法则为一个字符串，仅由左右括号和大写字母（'A'~'Z'）组成，保证括号是匹配的且输入合法！

输出描述：输出需要进行的乘法次数

示例1
输入：
    3
    50 10
    10 20
    20 5
	(A(BC))
输出：
	3500
*/
#include  <iostream>
using namespace std;
#include <vector>
#include <stack>

void print(vector<pair<int, int>> arr) {
    int i = 0;
    for(auto p:arr)
        printf("%c [%d x %d] \n",(i++ + 'A'), p.first, p.second);
}

int cal(vector<pair<int, int>> &arr, string &chars) {
    int result = 0;
    int a = chars.back() - 'A';
    chars.pop_back();
    int b = chars.back() - 'A';
    chars.pop_back();
    int col2 = arr[a].second;
    int row2 = arr[a].first;
    int col1 = arr[b].second;
    int row1 = arr[b].first;
    result = row1 * col1 * col2;
    chars.push_back(arr.size()+'A');
    arr.emplace_back(row1, col2);
    printf("[%d x %d] * [%d x %d] = %d , res : %d\n",
            row1, col1, row2, col2, row1 * col1 * col2, result);
    print(arr);
    return result;
}

int estimate(vector<pair<int, int>> arr, string rule) {
    string str;

    int len = arr.size();
    int idx = 0;
    int result = 0;
    for(idx = 0; idx < rule.size(); idx++) {
        char ch = rule[idx];
        printf("\ncur char : %c\n", ch);
        if(ch == ')') {
            int i = str.size() - 2;
            if(i >= 0 && str[i] == '(') {
                str[i] = str.back();
                str = str.substr(0, str.size() - 1);
            }
            i = i-1;
            if(i >= 0 && str[i] != '(') result += cal(arr, str);
            printf("%d -  %c   %s\n",i, str[i - 1], str.c_str());
        } else if (ch == '(') {
            str.push_back(ch);
        } else {
            int i = str.size();
            str.push_back(ch);
            printf("the remain str: %s , i = %d, %c \n", str.c_str(), i , str[i]);
            if(i == 0 || str[i - 1] == '(')  continue;
            result += cal(arr, str);
            printf(">>> the remain str: %s\n", str.c_str());
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> mat;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        mat.emplace_back(a,b);
    }
    string rule;
    cin >> rule;
    cout << estimate(mat, rule) << endl;
    return 0;
}
