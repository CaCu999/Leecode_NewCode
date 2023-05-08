/*
现有n种砝码，重量互不相等，分别为 m1,m2,m3…mn ；
每种砝码对应的数量为 x1,x2,x3...xn 。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。
注：称重重量包括 0

数据范围：每组输入数据满足1≤n≤10，1≤mi≤2000，1≤xi≤10
输入描述：
对于每组测试数据：
第一行：n --- 砝码的种数(范围[1,10])
第二行：m1 m2 m3 ... mn --- 每种砝码的重量(范围[1,2000])
第三行：x1 x2 x3 .... xn --- 每种砝码对应的数量(范围[1,10])
输出描述：

利用给定的砝码可以称出的不同的重量数
示例1
输入：
	2
	1 2
	2 1
输出：
	5
说明：可以表示出0，1，2，3，4五种重量。
*/

#include <iostream>
using namespace std;
#include <vector>

int getWeights(vector<int> weight, int max) {
    auto iter =weight.begin();
    int dp[max+1] = {0};
    dp[0] = 1;
    int num = 0;
    for(int i = 1; i <= weight.size(); i++) {
        for(int j = max; j >= 0; j--) {
            if(j >= *iter && dp[j - *iter])
                dp[j] = 1;
        }
        iter++;
    }
    for(int i = 0; i <= max; i++)
        if(dp[i])   num++;
    cout << num << endl;
}

int main() {    
    int n;
    cin >> n;
    vector<int> m(n);
    vector<int> x(n);
    vector<int> weight;
    int max = 0;
    int w,s;
    for(int i = 0; i < n; i++)
        cin >> m[i];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        max += m[i] * x[i];
        s = x[i];
        for(int j = 1; j < s; j*=2) {
            weight.push_back(m[i] * j);
            s -= j;
        }
        if(s > 0)   weight.push_back(m[i] * s);
    }
    getWeights(weight,max);
    return 0;
}