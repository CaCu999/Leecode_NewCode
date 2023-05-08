/*
到少输出统计结果，如果统计的个数相同，则按照ASCII码由小到大排序输出。
数据范围：字符串长度满足 1≤len(str)≤1000 

输入描述：一个只包含小写英文字母和数字的字符串。
输出描述：一个字符串，为不同字母出现次数的降序表示。若出现次数相同，则按ASCII码的升序输出。

示例1
输入：
	aaddccdc
输出：
	cda
说明：
样例里，c和d出现3次，a出现2次，但c的ASCII码比d小，所以先输出c，再输出d，最后输出a.
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <map>

map<char, int> chars;
void sortStr(string str) {
    chars.clear();
    for(auto ch: str)
        chars[ch]++;
    string res;
    sort(str.begin(), str.end());
    for(auto ch: str) {
        if(!res.empty() && ch == res.back())    continue;
        res.push_back(ch);
    }
    cout << res << endl;
    sort(res.begin(), res.end(),[](char a, char b){
        int na = chars[a];
        int nb = chars[b];
        if(na == nb)    return a < b;
        return na > nb;
    });
    cout << res << endl;
}

int main() {
    string str;
    cin >> str;
    sortStr(str);
    return 0;
}