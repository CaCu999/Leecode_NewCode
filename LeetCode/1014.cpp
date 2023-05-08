#include <iostream>
#include <string>
#include <mingw.thread.h>
using namespace std;

int func_1() {
    for(int i = 0;i < 100; i++) {
        cout <<this_thread::get_id<< "————————————————" << i << endl;
    }
}

int func_2(string s) {
    for(int i = 0;i < 100; i++) {
        cout << this_thread::get_id <<"        "<<s << "  --  " << i << endl;
    }
}

int main() {
    thread t1(func_1);
    thread t2(func_2,"Thread  ");

    t1.join();
    while(t2.joinable())
        t2.join();
    cout << this_thread::get_id << endl;
    return 0;
}