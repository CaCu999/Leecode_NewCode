/*
王强决定把年终奖用于购物，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
    主件	  附件
    电脑	  打印机，扫描仪
    书柜	  图书
    书桌	  台灯，文具
    工作椅	  无
如果要买归类为附件的物品，必须先买该附件所属的主件，且每件物品只能购买一次。
每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。
王强查到了每件物品的价格（都是 10 元的整数倍），而他只有 N 元的预算。除此之外，他给每件物品规定了一个重要度，用整数 1 ~ 5 表示。他希望在花费不超过 N 元的前提下，使自己的满意度达到最大。
满意度是指所购买的每件物品的价格与重要度的乘积的总和，假设设第i件物品的价格为v[i]，重要度为w[i]，共选中了k件物品，编号依次为j1,j2,...,jk，则满意度为：v[j1]*w[j1]+v[j2]*w[j2]+ … +v[jk]*w[jk]
请你帮助王强计算可获得的最大的满意度。

输入描述：
输入的第 1 行，为两个正整数N，m，用一个空格隔开：（其中 N （ N<32000 ）表示总钱数， m （m <60 ）为可购买的物品的个数。）
从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p q（其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。
如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）

输出描述： 输出一个正整数，为张强可以获得的最大的满意度。
示例1
输入：
	1000 5
	800 2 0
	400 5 1
	300 5 1
	400 3 0
	500 2 0
输出：
	2200
示例2
输入：
	50 5
	20 3 5
	20 3 5
	10 3 0
	10 2 0
	10 1 0
输出：
	130
说明：
由第1行可知总钱数N为50以及希望购买的物品个数m为5；
第2和第3行的q为5，说明它们都是编号为5的物品的附件；
第4~6行的q都为0，说明它们都是主件，它们的编号依次为3~5；
所以物品的价格与重要度乘积的总和的最大值为10*1+20*3+20*3=130  
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct object {
    int price;
    int weight;
    int quote;
    int values;
    object* quoteObj1;
    object* quoteObj2;
    object(): price(0), weight(0), quote(0), values(0), quoteObj1(nullptr), quoteObj2(nullptr) {}
    object(int p, int w, int q): price(p), weight(w), quote(q), values(price * weight), quoteObj1(nullptr), quoteObj2(nullptr) {}
    void setquote(object* obj) {
        if (!quoteObj1) quoteObj1 = obj;
        else if (!quoteObj2)    quoteObj2 = obj;
    }
};

int getMaxValue (vector<object> objs, int N, int m) {
    vector<object> mainObj;
    for(int i = 0; i <= m; i++) {
        int q = objs[i].quote;
        if(q){
            object* tmp = new object(objs[i].price, objs[i].weight, objs[i].quote);
            objs[q].setquote(tmp);
        }
    }
    for(int i = 0; i <= m; i++) {
        int q = objs[i].quote;
        if(!q)  mainObj.push_back(objs[i]);
    }
    m = mainObj.size();
    vector<vector<int>> dp( m, vector<int>(N / 10 + 1, 0));
    for (int i = 1; i < m; i++) {
        int ori = mainObj[i].price / 10;
        object obj = mainObj[i];
        for (int j = 1; j < dp[i].size(); j++) {
            //主件价格
            int cur = ori;
            //价格上限低于主件价格，不做处理
            if(j < cur) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            //只买主件，买和不买之间对比满意度
            int maxPrice = max(dp[i - 1][j], dp[i - 1][j - cur] + obj.values);
            if(obj.quoteObj1) {
                cur = ori + mainObj[i].quoteObj1->price / 10;
                maxPrice = j < cur ? maxPrice : max(maxPrice, dp[i - 1][j - cur] + obj.values + obj.quoteObj1->values);
            }
            if(obj.quoteObj2) {
                cur = ori + mainObj[i].quoteObj2->price / 10;
                maxPrice = j < cur ? maxPrice : max(maxPrice, dp[i - 1][j - cur] + obj.values + obj.quoteObj2->values);
                cur = cur + mainObj[i].quoteObj1->price / 10;
                maxPrice = j < cur ? maxPrice : max(maxPrice, dp[i - 1][j - cur] + obj.values + obj.quoteObj1->values + obj.quoteObj2->values);
            }
            dp[i][j] = maxPrice;
        }
        if(obj.quoteObj1 || obj.quoteObj2) {
            delete obj.quoteObj1;
            delete obj.quoteObj2;
        }
    }
    printf("%d\n",dp[m - 1][N/10]);
    return dp[m - 1][N/10];
}

int main() {
    int N;
    int m;
    cin >> N >> m;
    int v,p,q;
    vector<object> objs;
    objs.push_back(object());
    for(int i =1; i <= m; i++) {
        cin >> v >> p >> q;
        objs.push_back(object(v, p, q));
    }
    getMaxValue(objs, N, m);
    return 0;
}