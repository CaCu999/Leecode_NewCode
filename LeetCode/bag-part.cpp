#include <iostream>
#include <algorithm>
using namespace std;
/*
4 9
1 2		//2
2 4		//2
4 4		//1
4 5		//1.25

*/
struct Stuff{
    int weight;
    int value;
    float rate;
    bool operator < (Stuff other) const {
        return rate > other.rate;
    }
};

void bag() {
    int n,m;
    cin >> n >> m;
    Stuff* stuff = new Stuff[n];
    for(int i = 0; i < n; i++) {
        cin >> stuff[i].weight >> stuff[i].value;
        stuff[i].rate = stuff[i].value * 1.0/stuff[i].weight;
    }
    sort(stuff,stuff+n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if((stuff[i].weight + sum) <= m) {
            sum += stuff[i].weight;
            cout << stuff[i].weight << "  " << stuff[i].value << "  " << sum << endl;
        } else {
            float num =  (m - sum) * 1.0 /stuff[i].weight * 1.0;
            cout << num << "  " <<stuff[i].weight * num << "  " << stuff[i].value * num << endl;
            break;
        }        
    }
}

int main() {
    bag();
    return 0;
}