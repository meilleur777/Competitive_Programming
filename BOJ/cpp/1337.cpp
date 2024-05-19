#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    set<int> st;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int ans=4;
    for (auto p:st) {
        int res=4;
        for (int i=p+1; i<=p+4; i++) {
            if (st.find(i)!=st.end()) res--;
        }
        ans=min(ans, res);
    }
    cout << ans;


    return 0;
}
