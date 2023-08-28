#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> cnt(1e5+1, 0);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a==1) {
            bool flag=false;
            if (b==0) {
                if (cnt[0]>=1) {
                    flag=true;
                }
            }
            else {
                for (int i=1; i*i<=b; i++) {
                    if (cnt[i]>=1) {
                        cnt[i]--;
                        if (b%i==0 && b/i<=1e5 && cnt[b/i]>=1) {
                            flag=true;
                        }
                        cnt[i]++;
                    }
                    if (flag) break;
                }
            }
            cout << flag << '\n';
        }
        else if (a==2) {
            cnt[v[b-1]]--;
            v[b-1]=0;
            cnt[v[b-1]]++;
        }
    }

    return 0;
}
