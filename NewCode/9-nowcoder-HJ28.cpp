/*
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的 N （ N 为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
输入:
有一个正偶数 n ，表示待挑选的自然数的个数。后面给出 n 个具体的数字。
输出:
输出一个整数 K ，表示你求得的“最佳方案”组成“素数伴侣”的对数。

数据范围：1≤n≤100，输入的数据大小满足 2≤val≤30000 
输入描述：输入说明:1 输入一个正偶数 n;2 输入 n 个整数
输出描述：求得的“最佳方案”组成“素数伴侣”的对数。
示例1
输入：
	4
	2 5 6 13
输出：
	2
示例2
输入：
	2
	3 6
输出：
	0
*/
#include <iostream>
using namespace std;
#include <vector>

class Solution
{
private:
    vector<vector<bool>> allPair;
    vector<int> evVis;
    vector<int> odVis;
    vector<int> visited;
public:
    Solution(vector<int> ev, vector<int> od) {
        int m = ev.size();
        int n = od.size();
        allPair.resize(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isPrime(ev[i] + od[j]))  allPair[i][j] = true;
            }
        }
        evVis.resize(m, -1);
        odVis.resize(n, -1);
    } 

    bool isPrime(int num) {
        for(int i = 2; i < num/2; i++)
            if(num % i == 0)    return false;
        return true;
    }

    int dfs(int i) {
        for(int j = 0; j < odVis.size(); j++) {
            if(!visited[j] && allPair[i][j]) {
                visited[j] = true;
                if(odVis[j] == -1 || dfs(odVis[j])) {
                    evVis[i] = j;
                    odVis[j] = i;
                    return 1;
                }
            }
        }
        return 0;
    }

    int getCouple() {
        int res = 0;
        for(int i = 0; i < evVis.size(); i++) {
            visited.assign(odVis.size(),0);
            res += dfs(i);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> ev,od;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num % 2 == 0)
            od.push_back(num);
        else
            ev.push_back(num);
    }
    Solution sol(ev, od);
    cout << sol.getCouple() << endl;
    return 0;
}
