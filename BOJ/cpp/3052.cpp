#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    set<int> st;
    rep(i, 10) {
        int a;
        cin >> a;
        st.insert(a%42);
    }
    cout << (int)st.size();

    return 0;
}
