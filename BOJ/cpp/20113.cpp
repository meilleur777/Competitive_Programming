#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> cnt(n, 0);

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a==0) continue;
        cnt[a-1]++;
    }

    int mx=*max_element(cnt.begin(), cnt.end());
    int mxcnt=count(cnt.begin(), cnt.end(), mx);
    if (mxcnt==1) {
        cout << max_element(cnt.begin(), cnt.end())-cnt.begin()+1;
    }
    else cout << "skipped";

    return 0;
}
