/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
编辑距离的算法是首先由俄国科学家 Levenshtein 提出的，故又叫 Levenshtein Distance 。

例如：
字符串A: abcdefg
字符串B: abcdef
通过增加或是删掉字符 ”g” 的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
数据范围：给定的字符串长度满足 1≤len(str)≤1000 

输入描述：
每组用例一共2行，为输入的两个字符串
输出描述：
每组用例输出一行，代表字符串的距离

示例1
输入：
    abcdefg
    abcdef
输出：
	1
*/
#include <iostream>
using namespace std;
#include <vector>

int getStep(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1] = {0};
    for(int i = 1; i < m + 1; i++)
        dp[i][0] = i;
    for(int i = 1; i < n + 1; i++)
        dp[0][i] = i;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(str2[i - 1] == str1[j - 1])
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) + 1);
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    cout << dp[m][n] << endl;
    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    getStep(str1, str2);
    return 0;
}