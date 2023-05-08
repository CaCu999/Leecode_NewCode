/*
示例1
输入：A10;S20;W10;D30;X;A1A;B10A11;;A10;
输出：10,-10

示例2
输入：ABC;AKL;DA1;
输出：0,0
*/
#include <iostream>
using namespace std;
#include <vector>

bool isNum(char ch) {
    int num = ch - '0';
    return num >= 0 && num < 10;
}

pair<int,int> isOp(char ch) {
    switch (ch) {
        case 'A': return {-1, 0};
        case 'S': return { 0,-1};
        case 'W': return { 0, 1};
        case 'D': return { 1, 0};    
        default:  return { 0, 0};
    }
    return { 0, 0};
}

pair<int, int> operation(string str) {
    int fpos = 0;
    int epos = 0;
    vector<pair<int, int>> loc;
    loc.push_back({0, 0});
    cout << str.size() << endl;
    int len = 0;
    int num = 0;
    int s = 0;
    while((epos < str.size()) && (epos = str.find(';', epos))) {
        len = epos - fpos;
        auto [x, y] = isOp(str[fpos]);
        s = fpos;
        fpos = (epos++) + 1;
        if ((!x && !y) || len > 3 || len < 2 || !isNum(str[s+1])) continue;
        num = str[++s] - '0';
        if (len == 3 && !isNum(str[s+1]))   continue;
        if (len == 2) {
            loc.push_back({x * num, y * num});
            continue;
        }
        num = num * 10 + (str[++s] - '0');
        cout << num <<"  "<< epos << "   " << s << endl;
        loc.push_back({x * num, y * num});
    }
    int a = 0;
    int b = 0;
    for (auto [x, y]:loc) {
        printf("%d , %d \n",x,y);
        a += x;
        b += y;
    }
        printf("\n\n%d , %d \n",a,b);
    return {a , b};
        
}

int main() {
    string str;
    cin >> str;
    cout << str << endl;
    operation(str);
    return 0;
}