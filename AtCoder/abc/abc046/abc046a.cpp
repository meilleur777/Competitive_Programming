#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    set<int> st;
    for (int i=0; i<3; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << (int)st.size();

    return 0;
}
