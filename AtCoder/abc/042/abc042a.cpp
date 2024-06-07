#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<int> a(3);
    for (int i=0; i<3; i++) cin >> a[i];
    if (a==vector<int>{5, 5, 7} || 
        a==vector<int>{5, 7, 5} || 
        a==vector<int>{7, 5, 5}) cout << "YES";
    else cout << "NO";

    return 0;
}
