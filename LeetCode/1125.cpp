#include <iostream>
#include <vector>
#include "test.pb.h"
using namespace std;
template<typename T> 
void test(T) {
    cout << "aaaa" <<endl;
}
int main() {
    vector<int16_t> data;
    // data = {111,222,333,444,555,666,777,8191};
    all_data datavalue;
    datavalue.set_one(111);
    datavalue.set_two(222);
    for(int i = 0;i < 8; i++) {
        printf("%d  -  %d \n",i,data[i]);
    }
    return 0;
}