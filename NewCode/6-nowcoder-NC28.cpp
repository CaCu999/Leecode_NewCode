/*
给出两个字符串 s 和 t，要求在 s 中找出最短的包含 t 中所有字符的连续子串。

数据范围：0≤∣S∣,∣T∣≤10000，保证s和t字符串中仅包含大小写英文字母
要求：进阶：空间复杂度O(n) ， 时间复杂度O(n)
例如：S="XDOYEZODEYXNZ" T="XYZ"
找出的最短子串为"YXNZ".
注意：
如果 s 中没有包含 t 中所有字符的子串，返回空字符串 “”；
满足条件的子串可能有很多，但是题目保证满足条件的最短的子串唯一。

示例1
输入：
	"XDOYEZODEYXNZ","XYZ"
返回值：
	"YXNZ"
示例2
输入：
	"abcAbA","AA"
返回值：
	"AbA"
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <map>

class Solution {
public:

    string minWindow(string s, string t) {
        int count[256] = {0};
        for(auto ch:t)
            count[ch]++;
        int minLen = s.size();
        //len记录包含t中字符的个数
        int low = 0, high = 0, len = 0;
        string res;
        for (;high < s.size(); high++) {
            //右移上界，如果包含t元素，len++
            if(count[s[high]]-- > 0)  len++;
            // count[s[high]]--;
            //包含所有t中的字符，进入子循环
            while (len == t.size()) {
                if(high - low + 1 <= minLen) {
                    minLen = high - low + 1;
                    res = s.substr(low, minLen);
                    cout << len <<"     "<< res << endl;
                }
                //移动下界
                printf(">>>>  %c  %d\n",s[low],count[s[low]]);
                if(++count[s[low++]] > 0){
                    len--;
                }
            }
            
        }
        return res;
    }
};

int main() {
    string S,T;
    cin >> S;
    cin >> T; 
    Solution sol;
    cout << sol.minWindow(S,T) << endl;
    return 0;
}
