#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    getline(cin, s, '\n');

    int ans=0;
    stack<int> sk;
    for (auto c:s) {
        if (c=='(') {
            sk.push(0);
        }
        else if (c==')') {
            int height=sk.top();
            ans+=height+1;
            sk.pop();

            if (!sk.empty()) {
                int tmp=sk.top();
                sk.pop();
                sk.push(max(tmp, height+1));
            }
        }
    }

    cout << ans;

    return 0;
}
