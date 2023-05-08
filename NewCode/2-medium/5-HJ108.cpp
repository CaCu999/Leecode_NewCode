/*
计算一个浮点数的立方根，不使用库函数。
保留一位小数。
数据范围：∣val∣≤20 

输入描述：
待求解参数，为double类型（一个实数）
输出描述：
输出参数的立方根。保留一位小数。

示例1
输入：
	19.9
输出：
	2.7
示例2
输入：
	2.7
输出：
	1.4
*/
#include <iostream>
using namespace std;

int isRes(double n, double target) {
    n = n / 10;
    double res = n * n * n;
    if (res < target)   return -1;
    else if (res == target) return 0;
    else    return 1;    
}

void intRange(int &a, int &b, double target) {
    printf("range : %d %d , target %f\n" ,a,b,target);
    if(b == a + 1)    return;
    int size = b - a;
    int res = isRes(size / 2 + a, target);
    if (res  == 0) {
        a = a + size / 2;
        b = a;
        return ;
    } else if (res == -1)
        a = a + size / 2;
    else
        b = a + size / 2;
    intRange(a, b, target);
}

double getRes(double n) {
    bool isNegative = n < 0;
    int a = 0;
    int b = n * 10;
    if(isNegative) {
        n = -n;
        b = -b;
    }
    if (b < 10) b = 10;
    intRange(a, b, n);
    printf("(%d , %d)",a,b);
    double c = a * 1.0 / 10;
    double d = b * 1.0 / 10;
    double resA = n - c * c * c;
    double resB = n - d * d * d;
    if (resA < 0)   resA = -resA;
    if (resB < 0)   resB = -resB;
    printf("(%f , %f)",resA,resB);
    if (resA < resB)    return isNegative ? -c : c;
    else                return isNegative ? -c : d;
}

int main() {
    double n;
    cin >> n;
    cout << n << endl;
    printf("%0.1f",getRes(n));
    return 0;
}