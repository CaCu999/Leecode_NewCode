#include<iostream>
#include<mingw.thread.h>
#include<mingw.mutex.h>
#include<mingw.condition_variable.h>
using namespace std;
mutex m;
condition_variable cond;
int flag=10;
void fun(int num){
    for(int i=0;i<50;i++){
        unique_lock<mutex> lk(m);//A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
        while(flag!=num)
            cond.wait(lk);//在调用wait时会执行lk.unlock()
        cout<<"                                " << i << " -  ";
        for(int j=0;j<num;j++)
            cout<<j<<" ";
        cout<<endl;
        flag=(num==10)?100:10;
        cond.notify_one();//被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态
    }
}
int main(){
    cout << thread::hardware_concurrency() << endl;
    return 0;
}