/*
在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（注：能被*和?匹配的字符仅由英文字母和数字0到9组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
数据范围：字符串长度：1≤s≤100 
进阶：时间复杂度：O(n^2) ，空间复杂度：O(n) 
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

示例1
输入：
	te?t*.*
	txt12.xls
输出：
	false
示例2
输入：
    z
    zz
输出：
	false
示例3
输入：
	pq
	pppq
输出：
	false
示例4
输入：
	**Z
	0QZz
输出：
	true
示例5
输入：
	?*Bc*?
	abcd
输出：
	true
示例6
输入：
    h*?*a
    h#a
输出：
	false
说明： 根据题目描述可知能被*和?匹配的字符仅由英文字母和数字0到9组成，所以?不能匹配#，故输出false  

示例7
输入：
    p*p*qp**pq*p**p***ppq
    pppppppqppqqppqppppqqqppqppqpqqqppqpqpppqpppqpqqqpqqp
输出：
false
*/
#include <iostream>
using namespace std;

bool inRange(string str) {
    bool isCor = true;
    for(auto ch: str) {
        isCor = (ch >= '0' && ch <= '9');
        isCor = isCor || (ch >= 'a' && ch <= 'z');
        isCor = isCor || (ch >= 'A' && ch <= 'Z');
        isCor = isCor || ch == '?' || ch == '*' || ch == '.';
        if(!isCor)  return false;
    }
    return true;
}

string getLower(string str) {
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch >= 'A' && ch <= 'Z')  str[i] = str[i] - 'A' + 'a';
    }
    return str;
}

bool matchStr(string reg, string str) {
    if(!inRange(str))   return false;
    int i, j = 0;
    bool matchMulti = false;
    for(i = 0; i < str.size() && j < reg.size();) {
        if(reg[j] == '?') {
            j++;
            i++;
        printf("?  i %d  %c  j %d  %c\n", i, str[i], j, reg[j]);
            if(i >= str.size() && j >= reg.size())  return true;
            if(matchMulti)  i = i + str.substr(i).find_first_of(reg[j]);
        printf("?  i %d  %c  j %d  %c\n", i, str[i], j, reg[j]);
            continue;
        }
        if(reg[j] == '*') {
            if(reg.substr(j).find_first_not_of('*') == -1)  return true;
            matchMulti = true;
            j = j + reg.substr(j).find_first_not_of('*') - 1;
            char ch = reg[j + 1];
            if(ch == '?')   {
                j = j + 1;
                continue;
            }
            int tmp;
            if(reg.substr(j + 2).find_first_of(reg[j+1]) == -1)
                tmp = str.substr(i).find_last_of(ch);
            else
                tmp = str.substr(i).find_first_of(ch);
        printf("i %d  %c  j %d  %c  find  %c tmp %d \n", i, str[i], j, reg[j], ch, tmp);
            i = tmp == -1 ? i : i + tmp;
        printf("i %d  %c  j %d  %c  find  %c\n", i, str[i], j, reg[j], ch);
            j = j + 1;
            matchMulti = false;
            continue;
        }
        if(reg[j] != str[i])  return false;
        i++;j++;
    }
    if(i < str.size() || j < str.size()) return false;
    return true;
}
int main() {
    string regstr;
    string str;
    cin >> regstr;
    cin >> str;
    regstr = getLower(regstr);
    str = getLower(str);
    bool res = matchStr(regstr, str);
    if(res) cout << "true" << endl;
    else    cout << "false" << endl;
    return 0;
}