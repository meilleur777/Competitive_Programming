#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i=0; i<(int)(s.size()); i++) {
        if (s[i]=='A') continue;
        if ('Z'+1-s[i]>k) {

        }
        else {
            k-='Z'+1-s[i];
            s[i]='A';
        }
    }
    k%=26;
    s.back()+=k;
    cout << s;

    return 0;
}
