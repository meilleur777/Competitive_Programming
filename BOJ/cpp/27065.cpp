#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<int> a(5e3+1);
    for (int i=1; i<=5e3; i++) {
        set<int> st;
        for (int j=1; j*j<=i; j++) {
            if (i%j==0) {
                st.insert(j);
                st.insert(i/j);
            }
        }
        int sum=0;
        for (auto j:st) sum+=j;
        sum-=i;
        if (sum<i) a[i]=-1;
        else if (sum==i) a[i]=0;
        else a[i]=1;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag=false;
        if (a[n]==1) {
            flag=true;
            for (int j=1; j*j<=n; j++) {
                if (n%j==0) {
                    if (j!=n && a[j]==1) {
                        flag=false;
                    }
                    if (n/j!=n && a[n/j]==1) {
                        flag=false;
                    }
                }
            }
        }
        if (flag) cout << "Good Bye\n";
        else cout << "BOJ 2022\n";
    }

    return 0;
}
