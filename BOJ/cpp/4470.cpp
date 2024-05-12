#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
    for (int i=0; i<n; i++) {
        string s;
        getline(cin, s, '\n');
        cout << i+1 << ". " << s << '\n';
    }

    return 0;
}
