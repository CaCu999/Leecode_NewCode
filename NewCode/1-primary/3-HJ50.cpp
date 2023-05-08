/*
输入一个表达式（用字符串表示），求这个表达式的值。
保证字符串中的有效字符包括[‘0’-‘9’],‘+’,‘-’, ‘*’,‘/’ ,‘(’， ‘)’,‘[’, ‘]’,‘{’ ,‘}’。且表达式一定合法。

数据范围：表达式计算结果和过程中满足∣val∣≤1000，字符串长度满足1≤n≤1000 
输入描述：输入一个算术表达式
输出描述：得到计算结果

示例1
输入：
	3+2*{1+2*[-4/(8-6)+7]}
输出：
	25
*/
#include <iostream>
using namespace std;
#include <stack>

int getLevel(char ch) {
    switch (ch)
    {
    case '(':
    case '[':
    case '{':   return 0;
    case ')':
    case ']':
    case '}':   return 1;
    case '*':
    case '/':   return 2; 
    case '+':
    case '-':   return 3; 
    default:
        break;
    }
    return 4;
}

bool isNum(char ch) {
    if((ch - '0') >= 0 && (ch - '9') < 10)  return true;
    return false;
}

bool isCompare(char left, char right) {
    if(left == '(' && right == ')') return  true;
    if(left == '[' && right == ']') return  true;
    if(left == '{' && right == '}') return  true;
    return false;
}
#include <list>
void showChars(list<char> chars) {
    cout << "\t[";
    for(auto ch:chars) 
        printf("%c  ",ch);
        cout << "]\t";
}
void showChars(list<int> chars) {
    cout << "\t[";
    for(auto ch:chars) 
        printf("%d  ",ch);
        cout << "]\t";
}
//6*(-4+5)+10/5
string getExpression(string str) {
    string res = "";
    stack<char> chars;
    list<char> ls;
    int tmp = 0;
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(isNum(ch)){
            // tmp = tmp * 10 + ch - '0';
            res.push_back(ch);
            if(i == str.size() - 1 || (i < str.size() - 1 && !isNum(str[i+1])))  res.push_back(' ');
        } else {
            // cout << ch << "   " << res << endl;
            switch (getLevel(ch))
            {   case 0: 
                    chars.push(ch);
                    ls.push_back(ch);
                    showChars(ls);
                    cout <<" 0 [" << res << "]  cur -> " << ch <<endl;
                    break;     
                case 1: //当前元素为右括号
                    //栈顶是左括号时候退出栈        //判断左右括号是否匹配，匹配时退出循环
                    while(!chars.empty() && getLevel(chars.top()) && !isCompare(chars.top(), ch)) {
                        res.push_back(chars.top());
                        res.push_back(' ');
                        chars.pop();
                        ls.pop_back();
                        showChars(ls);
                        cout <<" 1 [" << res << "]  cur -> " << ch <<endl;
                    }
                    //弹出栈顶的左括号
                    if(!chars.empty() && !getLevel(chars.top())) { 
                        chars.pop();
                        ls.pop_back();
                        showChars(ls);
                        cout <<" 1-2 [" << res << "]  cur -> " << ch <<endl;
                    }
                    break;
                case 2:
                case 3:
                    if(ch == '-') {
                        if(i == 0 || !getLevel(str[i-1])) {
                            res.push_back('0');
                            res.push_back(' ');
                        }
                    }
                    //当前优先级低于栈顶优先级
                    while (!chars.empty()&& getLevel(chars.top()) && getLevel(chars.top()) <= getLevel(ch)) {
                        res.push_back(chars.top());
                        res.push_back(' ');
                        chars.pop();
                        ls.pop_back();
                        showChars(ls);
                        cout <<" 3 [" << res << "]  cur -> " << ch <<endl;
                    }
                    chars.push(ch);
                    ls.push_back(ch);
                    showChars(ls);
                    cout <<" 3-2 [" << res << "]  cur -> " << ch <<endl;
                    break;                    
                default:
                    break;
            }
        }
    }
    cout << res << "||" << endl;
    while(!chars.empty()) {
        res.push_back(chars.top());
        res.push_back(' ');
        char ch = chars.top();
        chars.pop();
        ls.pop_back();
        showChars(ls);
        cout <<" __ [" << res << "]  cur -> " << ch <<endl;
    }
    // res.push_back(' ');
    cout << res << "||" << endl;
    return res;
}

int getRes(int b, int a, char ch) {
    printf("cal: %d %c %d = ", b, ch, a);
    switch (ch) {
        case '+':   return  b + a;
        case '-':   return  b - a;
        case '/':   return  b / a;
        case '*':   return  b * a;
    }
    return 0;
}
#include <algorithm>
int caculate(string str) {
    stack<int> nums;
    list<int> ls;
    int tmp = 0;
    char ch = ' ';
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            if(ch == ' ')  {
                nums.push(tmp);
                ls.push_back(tmp);
                cout << "cur: ' ' push: " << tmp << "  " << endl;
                showChars(ls);
                tmp = 0;
            }
            else {
                int a = nums.top();
                nums.pop();
                ls.pop_back();
                int b = nums.top();
                nums.pop();
                ls.pop_back();
                cout << "cur: ' ' push: '" << ch << "'  " << endl;
                showChars(ls);
                tmp = getRes(b, a, ch);
                printf("%d\n",tmp);
                nums.push(tmp);
                ls.push_back(tmp);
                cout << "cur: ' ' push: " << tmp << "  " << endl;
                showChars(ls);
                tmp = 0;
                ch = ' ';
            }
        } else if (isNum(str[i])) {
            tmp = tmp * 10 + str[i] - '0';
        } else {
            ch = str[i];
        }
    }
    tmp = nums.empty() ? 0 : nums.top();
    if(!ls.empty()) showChars(ls);
    return tmp;
}

int main() {
    string str;
    cin >> str;
    cout << str << endl;
    str = getExpression(str);
    int n = caculate(str);
    cout << "the res is :  " << n << endl;
    return 0;    
}