/*
有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

示例1:
 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
示例2:
 输入：S = "ab"
 输出：["ab", "ba"]
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<string> permutation(string S) {
        vector<char> chars;
        chars.assign(S.begin(),S.end());
        sort(chars.begin(),chars.end());
        for(auto c : chars) {
            printf("%c  ",c);
        }
        vector<string> res;
        string tmp;
        printf("\n");
        do {
            for(int i = 0 ; i < S.size(); i++) {
                // printf("%c",chars[i]);
                tmp += chars[i];
            }
            res.push_back(tmp);
            tmp = "";
            // printf("\n");
        } while (next_permutation(chars.begin(),chars.end()));

        return res;
    }
};

int main() {
    string str;
    while(cin>>str) {
        cout << str << endl;
        if (getchar() == '\n')  break;
    }
    Solution sol;
    vector<string> res;
    res = sol.permutation(str);
    for(auto s: res) {
        cout << s << "    ";
    }
    cout << endl;
    return 0;
}