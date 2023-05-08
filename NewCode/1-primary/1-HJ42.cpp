/*
Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：

具体规则如下:
1.在英语读法中三位数字看成一整体，后面再加一个计数单位。从最右边往左数，三位一单位，例如12,345 等
2.每三位数后记得带上计数单位 分别是thousand, million, billion.
3.公式：百万以下千以上的数 X thousand X, 10亿以下百万以上的数：X million X thousand X, 10 亿以上的数：X billion X million X thousand X. 每个X分别代表三位数或两位数或一位数。
4.在英式英语中百位数和十位数之间要加and，美式英语中则会省略，我们这个题目采用加上and，百分位为零的话，这道题目我们省略and

下面再看几个数字例句：
22: twenty two
100:  one hundred
145:  one hundred and forty five
1,234:  one thousand two hundred and thirty four
8,088:  eight thousand (and) eighty eight (注:这个and可加可不加，这个题目我们选择不加)
486,669:  four hundred and eighty six thousand six hundred and sixty nine
1,652,510:  one million six hundred and fifty two thousand five hundred and ten

说明：
数字为正整数，不考虑小数，转化结果为英文小写；
保证输入的数据合法
关键字提示：and，billion，million，thousand，hundred。

数据范围：1≤n≤2000000 

输入描述：输入一个long型整数
输出描述：输出相应的英文写法

示例1
输入：
	22
输出：
	twenty two
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<string> letterList = { "", " thousand ", " million ", " billion "};
vector<string> numList = {"", "one", "two", "three", "four", "five", 
                "six", "seven", "eight", "nine"};
vector<string> tenList = {"ten", "eleven", "twelve", "thirteen", "fourteen", 
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
template<typename T>
void print(T nums) {
    printf("the vec is :  ");
    for(auto n : nums)
        cout << n << " ";
    cout << endl;
}

vector<int> long2Str(long n) {
    vector<int> nums;
    while(n) {
        nums.push_back(n % 1000);
        n = n / 1000;
    }
    print(nums);
    return nums;
}

string printNums(int n) {
    string res;
    if(n >= 100) {
        res.append(numList[n/100]);
        res.append(" hundred ");
        n = n % 100;
    }
    if(!res.empty() && n)    res.append("and ");
    if(n >= 10) {
        if(n >= 10 && n < 20) {
            res.append(tenList[n - 10]);
            return res;
        }
        switch (n / 10) {
            case 2: res.append("twenty");   break;
            case 3: res.append("thirty");   break;
            case 4: res.append("forty");    break;
            case 5: res.append("fifty");    break;
            case 6: res.append("sixty");    break;
            case 7: res.append("seventy");  break;
            case 8: res.append("eighty");   break;
            case 9: res.append("ninety");   break;
        }
        n = n % 10;
    }
    if(n && !res.empty() && res.back() != ' ')   res.push_back(' ');
    res.append(numList[n]);
    return res;
}

void getRes(vector<int> nums) {
    string str;
    for(int i = nums.size() - 1; i >= 0; i--) {
        str.append(printNums(nums[i]));
        str.append(letterList[i]);
    }
    cout << str << endl;
}

int main() {
    long n;
    cin >> n;
    vector<int> nums;
    nums = long2Str(n);
    getRes(nums);
    return 0;
}