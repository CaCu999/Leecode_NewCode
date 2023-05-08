/*
给出4个1-10的数字，通过加减乘除运算，得到数字为24就算胜利,除法指实数除法运算,运算符仅允许出现在两个数字之间,本题对数字选取顺序无要求，但每个数字仅允许使用一次，且需考虑括号运算
此题允许数字重复，如3 3 4 4为合法输入，此输入一共有两个3，但是每个数字只允许使用一次，则运算过程中两个3都被选取并进行对应的计算操作。

输入描述：
读入4个[1,10]的整数，数字允许重复，测试用例保证无异常数字。

输出描述：
对于每组案例，输出一行表示能否得到24点，能输出true，不能输出false

示例1
输入：
	7 2 1 10
输出：
	true
*/
#include <iostream>
using namespace std;
#include <vector>

bool getRes(vector<double> nums, double result) {
    if(nums.empty())    return result == 24;
    for(int i = 0; i < nums.size(); i++) {
        vector<double> rest(nums);
        rest.erase(rest.begin()+i);
        if(getRes(rest, result + nums[i]) || getRes(rest, result - nums[i]) ||
            getRes(rest, result * nums[i]) || getRes(rest, result / nums[i]))
            return true;
    }
    return false;
}

int main() {
    vector<double> nums(4, 0);
    for(int i = 0; i < 4; i++)
        cin >> nums[i];
    if(getRes(nums,0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}