/*
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。 

示例 1：
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：
输入：n = 0
输出：0
示例 3：
输入：n = 1
输出：0 
*/
#include <iostream>
using namespace std;
#include <vector>

// class Solution {
// public:
//     int countPrimes(int n) {
//         int res = 0;
//         bool isPrimes = true;
//         for (int i = 2; i < n; i++) {
//             isPrimes = true;
//             for (int j = 2; j * j <= i; j++) {
//                 if(i % j == 0)  isPrimes = false;
//             }
//             if (isPrimes){
//                 res++;
//                 printf("%d\n",i);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrimes(n,true);
        for (int i = 2; i * i < n; i++) {
            if (isPrimes[i])
                for (int j = i * i; j < n; j += i)
                    isPrimes[j] = false;
        }
        for (int i = 2; i < n; i++)
            if (isPrimes[i]) res++;
        return res;
    }
};


int main() {
    int n = 20;
    Solution sol;
    cout << sol.countPrimes(n) << endl;
    return 0;
}