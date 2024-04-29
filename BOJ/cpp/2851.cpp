#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<int> v(10);
    for (int i=0; i<10; i++) cin >> v[i];
    int ptr=0;
    int sum=0;
    while (ptr<10 && abs(100-sum)>=abs(100-(sum+v[ptr]))) {
        sum+=v[ptr];
        ptr++;
    }
    cout << sum;

    return 0;
}
