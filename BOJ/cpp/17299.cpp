#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(1e6+1, 0);
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    stack<int> sk;
    vector<int> ans(n);
    for (int i=0; i<n; i++) {
        while (!sk.empty() && cnt[a[sk.top()]]<cnt[a[i]]) {
            ans[sk.top()]=a[i];
            sk.pop();
        }
        sk.push(i);
    }
    while (!sk.empty()) {
        ans[sk.top()]=-1;
        sk.pop();
    }

    for (auto i:ans) cout << i << ' ';

    return 0;
}
