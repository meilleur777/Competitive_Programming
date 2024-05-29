#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<string> v(3);
    for (int i=0; i<3; i++) cin >> v[i];

    int now=0;
    vector<int> ptr(3, 0);
    while (true) {
        if (ptr[now]==v[now].size()) {
            cout << char('A'+now);
            break;
        }
        int nxt=v[now][ptr[now]]-'a';
        ptr[now]++;
        now=nxt;
    }

    return 0;
}
