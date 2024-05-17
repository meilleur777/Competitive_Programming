#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    unsigned long long n;
    cin >> n;
    if (n==1) cout << 0;
    else cout << (n/2)*((n+1)/2);

    return 0;
}
