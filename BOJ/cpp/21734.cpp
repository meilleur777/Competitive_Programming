#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    for (auto c:s) {
        int tmp=c;
        int cnt=0;
        while (tmp) {
            cnt+=tmp%10;
            tmp/=10;
        }
        rep(i, cnt) cout << c;
        cout << '\n';
    }

    return 0;
}
