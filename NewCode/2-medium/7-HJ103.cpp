/*
Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，
从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

数据范围：每组数据长度满足 1≤n≤200，数据大小满足 1≤val≤350 

输入描述：
数据共2行，第1行先输入数组的个数，第2行再输入梅花桩的高度

输出描述：输出一个结果

示例1
输入：
    6
    2 5 1 5 4 5 
输出：
	3
说明：
6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5 ，下标分别是 1 5 6
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5， 下标分别是 3 5 6
从第5格开始走最多有2步,4 5， 下标分别是 5 6
所以这个结果是3。 
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void print(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "  ";}
    cout << endl;
}
// 18
// 191 191 105 213 40 48 109 142 19 127 17 82 187 281 119 151 17 152 
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<int> maxStr;
    void getStep(vector<int> nums, int index) {
        for(int i = index; i < nums.size(); i++) {
            if(path.empty() && !maxStr.empty() && nums[i] > maxStr.front())    continue;
            if((nums.size() + path.size() - i) < maxStr.size())    break;
            if(path.empty()){
            cout << nums[i] << endl;
            print(maxStr);}
            if(!path.empty() && nums[i] <= path.back()) continue;
            path.push_back(nums[i]);
            getStep(nums, i + 1);
            path.pop_back();
        }
        res.push_back(path);
        if(maxStr.size() < path.size()){ maxStr = path;cout <<"change max " << endl;}
    }
};

void getRes(vector<int> nums) {
    vector<int> res(nums.size(), 1);
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                res[i] = max(res[j] + 1, res[i]);
            }
        }
    }
    print(res);
    int n = *max_element(res.begin(), res.end());
    cout << n << endl;
}

// 15
// 212 164 1 9 312 66 30 127 18 211 248 152 1 100 231 
int main() {
    int n;
    cin >> n;
    vector<int> nums(n,' ');
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    sol.getStep(nums,0);
    getRes(nums);
    return 0;
}