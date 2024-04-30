#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    int ptr=0;
    while (ptr<n && v[ptr]>t) {
        ptr++;
    }
    int tptr=ptr;
    while (tptr<n && v[tptr]==t) tptr++;

    if (ptr+1<=p && tptr+1<=p) {
        cout << ptr+1;
    }
    else cout << -1;

    return 0;
}
