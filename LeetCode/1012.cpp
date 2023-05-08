#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void displayArr(int* arr) {
    for(int i = 0; i < 10 ; i++)
        printf("  %d\t",arr[i]);
    printf("\n");
}

void sortArr() {
    int arr[10] = {5,43,654,88,1,6,40,7777,13,5};
    displayArr(arr);
    cout << endl;

    //自定义 从大到小排列
    sort(arr,arr + 10 , greater<int>());
    printf("the greater sort is  : ");
    displayArr(arr);

    //自定义 从小到大排列
    sort(arr,arr + 10 , less<int>());
    printf("the less sort is  : ");
    displayArr(arr);

    //普通排序
    sort(arr,arr + 10);
    printf("the normal sort is  : ");
    displayArr(arr);
}

void displayMap(map<int,float> mm) {
    map<int,float>::iterator iter = mm.begin();
    for(;iter != mm.end();iter ++)
        printf("\t[%d , %f]\n",iter->first,iter->second);
    cout<<endl;
}

void displayMap(map<int,float,greater<int>> mm) {
    // map<int,float,greater<int>>::iterator iter = mm.begin();
    auto iter = mm.begin();
    for(;iter != mm.end();iter ++)
        printf("\t[%d , %f]\n",iter->first,iter->second);
    cout<<endl;
}

bool cmpVect(pair<int,float> a,pair<int,float> b) {
    return a.second > b.second;
}

void displayVect(vector<pair<int,float>> mm) {
    vector<pair<int,float>>::iterator iter = mm.begin();
    for(;iter != mm.end();iter ++)
        printf("\t[%d , %f]\n",iter->first,iter->second);
    cout<<endl;
}

void sortMap() {
    map<int,float> nums;
    nums[0] = 0.6;
    nums[1] = 0.8;
    nums[2] = 0.16;
    nums[5] = 1.6;
    nums[3] = 0.663;
    nums[4] = 0.9;
    printf("normal sort:\n");
    displayMap(nums);
    
    map<int,float,greater<int>> numsGreater;
    numsGreater[0] = 0.6;
    numsGreater[1] = 0.8;
    numsGreater[2] = 0.16;
    numsGreater[5] = 1.6;
    numsGreater[3] = 0.663;
    numsGreater[4] = 0.9;
    printf("greater sort:\n");
    displayMap(numsGreater);

    vector<pair<int,float>> sortVect(nums.begin(),nums.end());
    sort(sortVect.begin(),sortVect.end(),cmpVect);
    printf("greater float sort:\n");
    displayVect(sortVect);
}

class Date{
    int year;
    int month;
    int day;
    Date(int a,int b,int c) {
        year = a;
        month = b;
        day = c;
    }
};

int main() {
    sortArr();
    sortMap();

    short a = 3150;
    short b = 6466;
    a = a * b;
    cout << a << endl;
    return 0;
}