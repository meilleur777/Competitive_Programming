#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ptr=1;
    stack<int> sk;
    string res;
    for (int i=0; i<n; i++) {
        while (ptr<=n && ptr<=a[i]) {
            sk.push(ptr);
            ptr++;
            res.push_back('+');
        }
        if (sk.top()==a[i]) {
            sk.pop();
            res.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for (auto c:res) cout << c << '\n';

    return 0;
}
