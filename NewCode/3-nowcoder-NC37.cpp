/*
给出一组区间，请合并所有重叠的区间。
请保证合并后的区间按区间起点升序排列。

数据范围：区间组数 0≤n≤2×10 ，区间内 的值都满足 0≤val≤2×10 
 
要求：空间复杂度 O(n)，时间复杂度 O(nlogn)
进阶：空间复杂度 O(val)，时间复杂度O(val)

示例1
输入：
	[[10,30],[20,60],[80,100],[150,180]]
返回值：
	[[10,60],[80,100],[150,180]]
示例2
输入：
	[[0,10],[10,20]]
返回值：
	[[0,20]]
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> getIntervalVec(string str) {
        vector<Interval> range;
        pair<int,int> p;
        char ch;
        int n = -1;
        int tmp;
        for(int i = 0; i < str.size(); i++) {
            ch = str[i];
            if (ch == ',' && str[i-1] != ']') {
                p.first = tmp;
                tmp = 0;
            } else if(ch == ']' && str[i-1] != ']') {
                p.second = tmp;
                range.push_back(Interval(p.first,p.second));
                tmp = 0;
            } else if ((ch - '0') <= 9 && (ch - '0') >= 0) {
                tmp = tmp * 10 + (ch - '0');
            }        
        }
        return range;        
    }
    vector<Interval> merge(string str) {
        vector<Interval> ranges = getIntervalVec(str);
        return merge(ranges);        
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() <= 1)   return intervals;
        vector<Interval> ranges = intervals;
        sort(ranges.begin(),ranges.end(),[](Interval a, Interval b){return a.start < b.start;});
        for(auto p:ranges) {
            printf("<%d,%d>\n",p.start,p.end);
        }
        int min = -1 ,max = -1;
        vector<Interval> res;
        min = ranges[0].start;
        max = ranges[0].end;
        for(int i = 1; i < ranges.size(); i++) {
            if(max < ranges[i].start) {
                res.push_back(Interval(min, max));
                min = ranges[i].start;
                max = ranges[i].end;
                continue;
            }
            if(max >= ranges[i].start && max <= ranges[i].end)  max = ranges[i].end;
            else if(min >= ranges[i].start && min <= ranges[i].end) min = ranges[i].start;
        }
        res.push_back(Interval(min, max));
        printf("[");
        for(int i = 0; i < res.size()-1; i++) {
            printf("[%d,%d],",res[i].start,res[i].end);
        }
        int n = res.size() - 1;
        if(res.size() > 0) printf("[%d,%d]",res[n].start,res[n].end);
        printf("]");
        return res;
    }
};

void getRange(string str) {
    vector<vector<int>> ranges;
    char ch;
    int n = -1;
    int tmp;
    for(int i = 0; i < str.size(); i++) {
        ch = str[i];
        if (ch == ',' && str[i-1] != ']') {
            ranges.push_back({});
            n++;
            ranges[n].push_back(tmp);
            tmp = 0;
        } else if(ch == ']' && str[i-1] != ']') {
            ranges[n].push_back(tmp);
            tmp = 0;
        } else if ((ch - '0') <= 9 && (ch - '0') >= 0) {
            tmp = tmp * 10 + (ch - '0');
        }        
    }
    sort(ranges.begin(),ranges.end());
    for(auto p:ranges) {
        printf("<%d,%d>\n",p[0],p[1]);
    }
    int min = -1 ,max = -1;
    vector<vector<int>> res;
    min = ranges[0][0];
    max = ranges[0][1];
    for(int i = 1; i < ranges.size(); i++) {
        if(max < ranges[i][0]) {
            res.push_back({min, max});
            min = ranges[i][0];
            max = ranges[i][1];
            continue;
        }
        if(max >= ranges[i][0] && max <= ranges[i][1])  max = ranges[i][1];
        else if(min >= ranges[i][0] && min <= ranges[i][1]) min = ranges[i][0];
    }
    res.push_back({min, max});
    printf("[");
    for(int i = 0; i < res.size()-1; i++) {
        printf("[%d,%d],",res[i][0],res[i][1]);
    }
    n = res.size() - 1;
    if(res.size() > 0) printf("[%d,%d]",res[n][0],res[n][1]);
    printf("]");
}

int main() {
    string str;
    cin >> str;
    getRange(str);
    Solution sol;
    cout << endl;
    sol.merge(str);
    return 0;
}