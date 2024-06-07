#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    if (max({a, b, c})*2==a+b+c) cout << "Yes";
    else cout << "No";

    return 0;
}
