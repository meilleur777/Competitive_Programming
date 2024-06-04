#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<string> v({"chunbae", "nabi", "yeongcheol"});
    int flag=-1;
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            char c;
            cin >> c;

            if (c=='w') flag=0;
            else if (c=='b') flag=1;
            else if (c=='g') flag=2;
        }
    }

    cout << v[flag];

    return 0;
}
