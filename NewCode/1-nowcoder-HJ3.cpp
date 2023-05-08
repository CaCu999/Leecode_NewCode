/*
示例1
输入：
3
2
2
1
输出：
1
2
复制
说明：
输入解释：
第一个数字是3，也即这个小样例的N=3，说明用计算机生成了3个1到500之间的随机整数，接下来每行一个随机数字，共3行，也即这3个随机数字为：
2
2
1
所以样例的输出为：
1
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    int m;
    int tmp;
    cin >> m;
    vector<int> nums;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    for(int i = 0; i < m; i++) {
        printf("%d    ",nums[i]);
    }
    printf("\n");
    sort(nums.begin(),nums.end());
    for(int i = 0; i < m; i++) {
        if(i == 0 || tmp != nums[i]) {
            tmp = nums[i];
            cout << tmp << endl;
        }
    }
    return 0;
}