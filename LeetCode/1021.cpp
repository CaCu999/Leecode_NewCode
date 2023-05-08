#include <iostream>
#include <mingw.thread.h>
#include <mingw.mutex.h>
#include <time.h>
using namespace std;
static int a = 0;
mutex mm;
void func1() {
    cout << "   " << __func__ <<"   id  "  << this_thread::get_id << endl;
    for(int i = 0 ; i < 100; i++) {
        mm.lock();
        Sleep(1);
        a+=2;
        mm.unlock();
        // cout << __func__ << " __  " << a << endl;
    }
}

void func2() {
    cout << "   " << __func__ <<"   id  "  << this_thread::get_id << endl;
    for(int i = 0 ; i < 100; i++) {
        // mm.lock();
        lock_guard<mutex> lock(mm);
        Sleep(1);
        a--;
        // cout << __func__ << " __  " << a << endl;
        // mm.unlock();
    }
}

int main() {
    time_t now_time = time(NULL);
    tm* t_tm = localtime(&now_time);
    // cout << now_time << endl;
    cout << "   " << __func__ <<"   id  "  << this_thread::get_id << endl;
    for(int i = 0 ; i < 100; i++) {
        thread t1(func1);
        t1.detach();
    cout << "   " << __func__ <<"   id  "  << t1.get_id() << endl;
    }
    thread t2(func2);
    t2.detach();
    cout << "   " << __func__ <<"   id  "  << t2.get_id() << endl;
    cout << __func__ << "    " << a <<"                 time  "<< time(NULL) - now_time<< endl;
    system("pause");
    return 0;
}