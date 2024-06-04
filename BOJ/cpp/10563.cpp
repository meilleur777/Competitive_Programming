#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int pivot=find(a.begin(), a.end(), 1)-a.begin();

        vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(2, -1)));
        function<bool(int, int, int)> dp=[&](int left, int right, int parity) {
            if (left==right && left==pivot) {
                return true;
            }

            int& ret=cache[left][right][parity];
            if (ret!=-1) return !!ret;

            ret=0;
            for (int i=left; i<pivot; i++) {
                if ((i==left || a[i-1]<a[i]) && a[i]>a[i+1])  {
                    ret|=!dp(i+1, right, (parity+i-left)%2);
                }
            }
            for (int i=pivot+1; i<=right; i++) {
                if (a[i-1]<a[i] && (i==right || a[i]>a[i+1])) {
                    ret|=!dp(left, i-1, (parity+right-i)%2);
                }
            }
            if (parity==1) {
                ret|=!dp(left, right, 0);
            }

            return !!ret;
        };

        if (dp(0, n-1, 0)) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}
