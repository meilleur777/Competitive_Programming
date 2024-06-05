#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> numList(n);
    for (int i=0; i<n; i++) cin >> numList[i];

    int mxLen=numList.front().size();
    for (int i=1; i<=mxLen; i++) {
        set<string> st;
        for (auto s:numList) {
            st.insert(s.substr(mxLen-i, i));
        }

        if ((int)st.size()==n) {
            cout << i;
            break;
        }
    }

    return 0;
}
