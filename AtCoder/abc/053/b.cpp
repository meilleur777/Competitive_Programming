#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();
    int left, right;
    for (int i=0; i<n; i++) {
        if (s[i]=='A') {
            left=i;
            break;
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (s[i]=='Z') {
            right=i;
            break;
        }
    }
    
    cout << right-left+1;

    return 0;
}
