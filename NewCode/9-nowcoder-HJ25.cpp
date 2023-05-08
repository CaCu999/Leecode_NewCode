/*
信息社会，有海量的数据需要分析处理，比如公安局分析身份证号码、 QQ 用户、手机号码、银行帐号等信息及活动记录。
采集输入大数据和分类规则，通过大数据分类处理程序，将大数据分类输出。

数据范围：1≤I,R≤100  ，输入的整数大小满足 0≤val≤2^31−1 
输入描述：一组输入整数序列I和一组规则整数序列R，I和R序列的第一个整数为序列的个数（个数不包含第一个整数）；
整数范围为0~(2^31)-1，序列个数不限
输出描述：从R依次中取出R<i>，对I进行处理，找到满足条件的I： 
I整数对应的数字需要连续包含R<i>对应的数字。比如R<i>为23，I为231，那么I包含了R<i>，条件满足 。 
按R<i>从小到大的顺序:
(1)先输出R<i>； 
(2)再输出满足条件的I的个数； 
(3)然后输出满足条件的I在I序列中的位置索引(从0开始)； 
(4)最后再输出I。 
附加条件： 
(1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I，索引大的需要过滤掉 
(2)如果没有满足条件的I，对应的R<i>不用输出 
(3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(不包含“个数”本身)
 
序列I：15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123（第一个15表明后续有15个整数） 
序列R：5,6,3,6,3,0（第一个5表明后续有5个整数） 
输出：30, 3,6,0,123,3,453,7,3,9,453456,13,453,14,123,6,7,1,456,2,786,4,46,8,665,9,453456,11,456,12,786
说明：
30----后续有30个整数
3----从小到大排序，第一个R<i>为0，但没有满足条件的I，不输出0，而下一个R<i>是3
6--- 存在6个包含3的I 
0--- 123所在的原序号为0 
123--- 123包含3，满足条件 
示例1
输入：
    15 123 456 786 453 46 7 5 3 665 453456 745 456 786 453 123
    5 6 3 6 3 0
输出：
    30 3 6 0 123 3 453 7 3 9 453456 13 453 14 123 6 7 1 456 2 786 4 46 8 665 9 453456 11 456 12 786
说明：
    将序列R：5,6,3,6,3,0（第一个5表明后续有5个整数）排序去重后，可得0,3,6。
    序列I没有包含0的元素。
    序列I中包含3的元素有：I[0]的值为123、I[3]的值为453、I[7]的值为3、I[9]的值为453456、I[13]的值为453、I[14]的值为123。
    序列I中包含6的元素有：I[1]的值为456、I[2]的值为786、I[4]的值为46、I[8]的值为665、I[9]的值为453456、I[11]的值为456、I[12]的值为786。
    最后按题目要求的格式进行输出即可。
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> sortAndDel(vector<int> nums) {
    sort(nums.begin(), nums.end());
    if(nums.size() <= 1)    return nums;
    int pre = nums[0];
    vector<int> res;
    res.push_back(pre);
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != pre) {
            pre = nums[i];
            res.push_back(pre);
        }
    }
    return res;
}

bool isRight(int x, int y) {
    string a = to_string(x);
    string b = to_string(y);
    for(int i = 0; i < a.size(); i++)
        if(a[i] == b[0] && !a.substr(i,b.size()).compare(b))
            return true;
    return false;
}

//取出R[i],对I进行处理，找到满足条件的I
//条件：I证书对应的数字需要连续包含R[i]，对I进行处理
vector<vector<pair<int,int>>> getRes(vector<int> I, vector<int> R) {
    //R[i]从小到大的顺序
    R = sortAndDel(R);
    vector<vector<pair<int,int>>> res(R.size(), vector<pair<int,int>>());
    for(int i = 0; i < R.size(); i++) {
        for(int j = 0; j < I.size(); j++) {
            if(isRight(I[j],R[i])) res[i].push_back({j, I[j]});
        }
    }
    int num = 0;
    for(int i = 0; i < res.size(); i++) {
        if(res[i].size())  num = num + 2 + 2 * res[i].size();
    }
    printf("%d ",num);
    for(int i = 0; i < res.size(); i++) {
        if(!res[i].size())  continue;
        //先输出R[i] 输出满足条件的I的个数
        printf("%d %d ", R[i], res[i].size());
        for(int j = 0; j < res[i].size(); j++) {
            //输出满足条件的I在I序列中的位置索引 输出I
            printf("%d %d ",res[i][j].first,res[i][j].second);
        }
    }
    printf("\n");
    return res;
}

int main() {
    int m;
    cin >> m;
    vector<int> I(m);
    for(int i = 0; i < m; i++)
        cin >> I[i];
    int n;
    cin >> n;
    vector<int> R(n);
    for(int i = 0; i < n; i++)
        cin >> R[i];
    getRes(I,R);
    return 0;
}