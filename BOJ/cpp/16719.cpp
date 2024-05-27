#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        
    string s;
    cin >> s;
    int n=s.size();
    vector<bool> isIn(n, false);

    int num=0;
    vector<int> order(n, -1);
    function<void(int, int)> sol=[&](int left, int right) {
        if (left>right) return;
        int mnInd=min_element(s.begin()+left, s.begin()+right+1)-s.begin();
        order[mnInd]=num;
        num++;
        sol(mnInd+1, right);
        sol(left, mnInd-1);
    };
    sol(0, n-1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (order[j]==i) {
                isIn[j]=true;
                break;
            }
        }

        for (int k=0; k<n; k++) {
            if (isIn[k]) cout << s[k];
        }
        cout << '\n';
    }

    return 0;
}
