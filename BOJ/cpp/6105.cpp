#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
        
    stack<int> sk;
    vector<int> ans(n);
    for (int i=0; i<n; i++) {
        while (!sk.empty() && v[sk.top()]<v[i]) {
            ans[sk.top()]=i+1;
            sk.pop();
        }
        sk.push(i);
    }
    while (!sk.empty()) {
        ans[sk.top()]=0;
        sk.pop();
    }

    for (auto i:ans) cout << i << '\n';

    return 0;
}
