#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long a, b, x;
    cin >> a >> b >> x;
    long long bbb=b/x+1;
    long long aaa=(a-1)/x+1;
    if (a==0) aaa=0;
    if (b==0) bbb=1;
    cout << bbb-aaa;

    return 0;
}
