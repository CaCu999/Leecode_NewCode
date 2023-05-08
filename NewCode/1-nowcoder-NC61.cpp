/*
给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
（注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
 
要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)
    
示例1
输入:		[3,2,4],6
返回值：	[2,3]
说明：
因为 2+4=6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2,3]
    
示例2
输入：		[20,70,110,150],90
返回值：	[1,2]
复制
说明：		20+70=90
*/
#include <iostream>
using namespace std;
#include <map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> nums;
        int tmp;
        for(int i = 0; i < numbers.size(); i++) {
            tmp = numbers[i];
            if(!nums[tmp])
                nums[tmp] = i + 1;
            printf(" %d  -- %d\n",tmp,nums[tmp]);
        }
        printf("\n");
        int index;
        for(int i = 0; i < numbers.size(); i++) {
            tmp = target - numbers[i];
            index = nums[tmp];
            printf(" %d  -- %d\n",tmp,index);
            if(index && index != i + 1) {
                if(index > i + 1)   return {i + 1, index};
                else        return {index, i + 1};
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution sol;
    sol.twoSum(nums, target);
    return 0;
}