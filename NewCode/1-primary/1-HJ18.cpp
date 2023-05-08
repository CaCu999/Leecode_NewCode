/*
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
所有的IP地址划分为 A,B,C,D,E五类
A类地址从1.0.0.0到126.255.255.255;
B类地址从128.0.0.0到191.255.255.255;
C类地址从192.0.0.0到223.255.255.255;
D类地址从224.0.0.0到239.255.255.255；
E类地址从240.0.0.0到255.255.255.255

私网IP范围是：
从10.0.0.0到10.255.255.255
从172.16.0.0到172.31.255.255
从192.168.0.0到192.168.255.255

子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
（注意二进制下全是1或者全是0均为非法子网掩码）

注意：
1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
2. 私有IP地址和A,B,C,D,E类地址是不冲突的

输入描述：
多行字符串。每行一个IP地址和掩码，用~隔开。
请参考帖子https://www.nowcoder.com/discuss/276处理循环输入的问题。
输出描述：
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。

示例1
输入：
    10.70.44.68~255.254.255.0
    1.0.0.1~255.0.0.0
    192.168.0.2~255.255.255.0
    19..0.~255.255.255.0
输出：
	1 0 1 0 0 2 1
说明：
10.70.44.68~255.254.255.0的子网掩码非法，19..0.~255.255.255.0的IP地址非法，所以错误IP地址或错误掩码的计数为2；
1.0.0.1~255.0.0.0是无误的A类地址；
192.168.0.2~255.255.255.0是无误的C类地址且是私有IP；
所以最终的结果为1 0 1 0 0 2 1 

示例2
输入：
    0.201.56.50~255.255.111.255
    127.201.56.50~255.255.111.255
输出：
	0 0 0 0 0 0 0
说明：类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略  
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

string change2Str(int n) {
    string str;
    while(n) {
        int a = n % 2;
        str.push_back(a + '0');
        n = n / 2;
    }
    n = 8 - str.size();
    while(n--)
        str.push_back('0');
    reverse(str.begin(), str.end());
    return str;
}

bool isValid(string str, vector<int> &address) {
    int i = 0;
    vector<int> potIndex;
    int n = 3;
    while (n--) {
        i = i + str.substr(i).find('.');
        if(i == -1) break;
        potIndex.push_back(i++);
    }
    int s = 0;
    i = 0;
    if(potIndex.size() != 3)    return false;
    for(int k = 0; k < potIndex.size(); k++) {
        s = i;
        i = potIndex[k];
        if(i == s)  return false;
        if(i == 0 || i == str.size() - 1)   return false;
        address.push_back(atoi(str.substr(s,i-s).c_str()));
        i++;
    }
    n = atoi(str.substr(i).c_str());
    address.push_back(n);
    return true;
}

bool skipAddress(int a) {
    if(a == 0 || a == 127)  return true;
    return false;
}

int getType(int n) {
    if (n >=1 && n < 127)    return 1;
    else if (n >= 128 && n < 192)   return 2;
    else if (n >= 192 && n < 224)   return 3;
    else if (n >= 224 && n < 240)   return 4;
    else if (n >= 240 && n <= 255)  return 5;
    return 0;    
}

bool isPerson(vector<int> s) {
    if (s[0] == 10) return true;
    else if (s[0] == 172 && s[1] >= 16 && s[1] <= 31)    return true;
    else if (s[0] == 192 && s[1] == 168) return true;
    return false;
}

void countIP(string str, vector<int> &ips) {
    int i = str.find_first_of('~');
    string ip = str.substr(0,i);
    string end = str.substr(i + 1);
    vector<int> startAddress;
    vector<int> endAddress;
    
    if(!isValid(ip, startAddress) || !isValid(end, endAddress)){
        if(skipAddress(startAddress[0])) return;
        ips[5]++;
        printf("error: invalid ip  %d\n",ips[5]);
        return;
    }
    if(skipAddress(startAddress[0])) return;
    bool isChange = false;
    for(int i = 0; i < endAddress.size(); i++) {
        string str = change2Str(endAddress[i]);
        for(auto c:str) {
            if(!isChange && c == '1')       continue;
            else if(!isChange && c == '0')  isChange = true;
            else if(isChange && c == '1') {
                ips[5]++;
                printf("error: wrong end ip  %d\n",ips[5]);
                return;
            }
        }
    }
    if(!isChange) {
        ips[5]++;
        printf("error: end ip cannot be all 1  %d\n",ips[5]);
        return;
    }
    int a = getType(startAddress[0]);
    if(!a) {
        ips[5]++;
        printf("error: No ip Type  %d\n",ips[5]);
        return;
    }
    ips[a - 1]++;
    if(isPerson(startAddress))  ips[6]++;
}

int main() {
    vector<string> strs={
                "225.240.129.203~255.110.255.255",
		"183.181.49.4~255.0.0.0",
		"172.177.113.45~255.0.0.0",
		"176.134.46.246~255.0.0.0",
		        "153.63.21.56~255.255.58.255",
		"23.135.167.228~255.0.0.0",
		"204.58.47.149~255.0.0.0",
		"113.33.181.46~255.255.255.0",
		        "73.245.52.119~255.255.154.0",
		"23.214.47.71~255.0.0.0",
		        "139.124.188.91~255.255.255.100",
		"142.94.192.197~255.0.0.0",
		"53.173.252.202~255.0.0.0",
            "127.201.56.50~255.255.111.255",
		"118.251.84.111~255.0.0.0",
		"130.27.73.170~255.0.0.0",
		        "253.237.54.56~255.86.0.0",
		        "64.189.222.111~255.255.255.139",
		"148.77.44.147~255.0.0.0",
		"59.213.5.253~255.255.0.0",
		"3.52.119.131~255.255.0.0",
		"213.208.164.145~255.255.0.0",
		        "24.22.21.206~255.255.90.255",
		"89.43.34.31~255.0.0.0",
		"9.64.214.75~255.0.0.0",
		        "110.156.20.173~255.153.0.0",
		"71.183.242.53~255.255.0.0",
		"119.152.129.100~255.0.0.0",
		"38.187.119.201~255.0.0.0",
		        "73.81.221.180~255.255.255.255",
		        "73.198.13.199~255.0.15.0",
		"99.42.142.145~255.255.255.0",
		"196.121.115.160~255.0.0.0",
		"226.30.29.206~255.0.0.0",
		        "244.248.31.171~255.255.255.255",
		"59.116.159.246~255.0.0.0",
		        "121.124.37.157~255.0.0.226",
		"103.42.94.71~255.255.0.0",
		        "125.88.217.249~255.255.74.255",
		"73.44.250.101~255.255.255.0"
    };
    vector<int> ips(7, 0);
    for(int i = 0; i < strs.size(); i++)
        countIP(strs[i], ips);
    for(int i = 0; i < 6; i++)
        printf("%d ",ips[i]);
    printf("%d\n", ips[6]);
    cout << change2Str(10) << endl;
    return 0;
}