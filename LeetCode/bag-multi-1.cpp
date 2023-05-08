#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void bag2(){
    int n,m;
    cin >> n >> m;
    int v,w,s;
    list<int> vv,ww;
    for(int i = 1; i <= n; i++) {
        //输入大小、价值、个数
        cin >> v >> w >> s;
        //以1、2、4...的倍数放入物品
        for(int j = 1; j <= s; ) {
            vv.push_back(j*v);
            ww.push_back(j*w);
            s -= j;
            j *= 2;
        }
        //最后多余的物品为一组
        if(s > 0) {
            vv.push_back(s*v);
            ww.push_back(s*w);
        }
    }
    list<int>::iterator itv=vv.begin();
    list<int>::iterator itw=ww.begin();
    int dp[vv.size()+1][m+1];
    for(int i = 0; i <= vv.size(); i++)
        dp[i][0] = 0;
    for(int i = 0; i <= m; i++)
        dp[0][i] = 0;
    //01背包
    for(int i = 1; i <= vv.size(); i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= *itv)
                dp[i][j] = max(dp[i][j],dp[i-1][j-*itv] + *itw);
        }
        itv++;
        itw++;
    }
}

void bag1() {
    
    int n,m;
    cin >> n >> m;
    int v,w,s;
    list<int> vv,ww;
    for(int i = 1; i <= n; i++) {
        //输入大小、价值、个数
        cin >> v >> w >> s;
        //以1、2、4...的倍数放入物品
        for(int j = 1; j <= s; ) {
            vv.push_back(j*v);
            ww.push_back(j*w);
            s -= j;
            j *= 2;
        }
        //最后多余的物品为一组
        if(s > 0) {
            vv.push_back(s*v);
            ww.push_back(s*w);
        }
    }
    list<int>::iterator itv=vv.begin();
    list<int>::iterator itw=ww.begin();
    int dp[m+1];
    for(int i = 0; i <= m; i++)
        dp[i] = 0;
    //01背包
    for(int i = 1; i <= vv.size(); i++) {
        for(int j = m; j >= 0; j--) {
            if(j >= *itv)
                dp[j] = max(dp[j],dp[j-*itv] + *itw);
        }
        itv++;
        itw++;
    }
}
/*
4 5
1 2 3
2 4 1
3 4 3
4 5 2
*/
int main() {
    bag1();
    return 0;
}