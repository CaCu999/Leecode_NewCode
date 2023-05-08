#include <iostream>
#include <mingw.thread.h>
using namespace std;

void func(int i) {
    while (1)
    {
        cout << i++ << endl;
    }
    
}

int main() {
    thread td(func,0);
    td.join();
    return 0;
}