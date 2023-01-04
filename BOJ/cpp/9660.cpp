#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n;
    cin >> n;
    n%=7;
    if (n==2 || n==0) cout << "CY";
    else cout << "SK";

    return 0;
}
