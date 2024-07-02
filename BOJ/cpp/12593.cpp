#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    for (int tc=1; tc<=t; tc++) {
        int ans=0;

        int r, k, n;
        cin >> r >> k >> n;
        vector<int> group(n);
        for (int i=0; i<n; i++) cin >> group[i];

        int ptr=0;
        while (r--) {
            int now=0;
            set<int> st;
            while (st.find(ptr)==st.end() && now+group[ptr]<=k) {
                now+=group[ptr];
                ans+=group[ptr];
                st.insert(ptr);
                ptr=(ptr+1)%n;
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n'; 
    }

    return 0;
}
