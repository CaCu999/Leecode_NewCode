#include <iostream>
#include <algorithm>
using namespace std;
/*
4 10
5
2
3
1
*/
void bag() {
    int n,m;
    cin >> n >> m;
    int w[n];
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w,w+n);
    int sum = 0;
    for(int i = 0; (sum + w[i]) <= m; i++) {
        sum += w[i];
        cout << w[i] <<"  ";
    }
    cout << endl;
}
int main() {
    bag();
    return 0;
}