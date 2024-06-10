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

    int tmp=st.size();
    if (tmp%2==0) cout << tmp-1;
    else cout << tmp;

    return 0;
}
