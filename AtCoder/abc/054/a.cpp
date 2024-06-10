#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    if (a==1) a+=13;
    if (b==1) b+=13;

    if (a>b) cout << "Alice";
    else if (a==b) cout << "Draw";
    else cout << "Bob";

    return 0;
}
