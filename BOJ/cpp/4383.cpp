#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        set<int> st;
        for (int i=0; i<n-1; i++) {
            st.insert(abs(a[i+1]-a[i]));
        }

        bool isJolly=true;
        for (int i=1; i<n; i++) {
            if (st.find(i)==st.end()) isJolly=false;
        }

        if (isJolly==true) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0;
}
