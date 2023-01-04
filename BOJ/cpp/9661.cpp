#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n;
    cin >> n;
    n%=5;
    if (n==0 || n==2) cout << "CY";
    else cout << "SK";

    return 0;
}
