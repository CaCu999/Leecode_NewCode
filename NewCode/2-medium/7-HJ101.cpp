/*
输入整型数组和排序标识，对其元素按照升序或降序进行排序

数据范围： 1≤n≤1000 ，元素大小满足 0≤val≤100000 
输入描述：
第一行输入数组元素个数
第二行输入待排序的数组，每个数用空格隔开
第三行输入一个整数0或1。0代表升序排序，1代表降序排序

输出描述：输出排好序的数字

示例1
输入：
    8
    1 2 4 9 3 55 64 25
    0
输出：
	1 2 3 4 9 25 55 64
示例2
输入：
    5
    1 2 3 4 5
    1
输出：
	5 4 3 2 1
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(vector<int> nums) {
    for(auto a: nums)
        printf("%d ",a);
    printf("\b\n");
}

void sortNum(vector<int> nums, int isDec) {
    if(isDec)
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
    else
        sort(nums.begin(), nums.end());
    print(nums);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int isDec = 0;
    cin >> isDec;
    sortNum(nums, isDec);
    return 0;
}