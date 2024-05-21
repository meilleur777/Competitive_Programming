#include <bits/stdc++.h>
using namespace std;

//Two-pointer
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    
    int right=0;
    long long ans=0;
    vector<int> cnt(1e5+1, 0);
    for (int left=0; left<n; left++) {
        while (right<n && cnt[v[right]]<1) {
            cnt[v[right]]++;
            right++;
        }
        ans+=right-left;
        cnt[v[left]]--;
    }
    cout << ans;

    return 0;
}
