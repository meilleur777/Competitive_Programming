#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m, 0);
    vector<vector<int>> arc(n);
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        while (num--) {
            int a;
            cin >> a;
            a--;
            cnt[a]++;
            arc[i].push_back(a);
        }
    }

    for (int i=0; i<n; i++) {
        vector<int> tmpCnt=cnt;
        for (auto nxt:arc[i]) {
            tmpCnt[nxt]--;
        }

        bool flag=true;
        for (int j=0; j<m; j++) {
            if (tmpCnt[j]<=0) {
                flag=false;
                break;
            }
        }

        if (flag) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
