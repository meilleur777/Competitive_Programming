#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3)); //L, H, R
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }

    sort(v.begin(), v.end(), [&](const vector<int>& p, const vector<int>& q) -> bool {
        if (p[0]==q[0]) {
            if (p[1]==q[1]) {
                return p[2]>q[2];
            }
            return p[1]>q[1];
        }
        return p[0]<q[0];
    });

    // vector<pair<int, int>> ans;
    set<pair<int, int>> st;
    for (int i=0; i<n; i++) {
        pair<int, int> left={v[i][0], v[i][1]};
        pair<int, int> right={v[i][2], v[i][1]};
        auto leftfirst=st.lower_bound(left);
        auto leftsecond=st.upper_bound(left);
        auto rightfirst=st.lower_bound(right);
        auto rightsecond=st.upper_bound(right);
        pair<int, int> nxtleft={-1, -1};
        pair<int, int> nxtright={-1, -1};
        vector<set<pair<int, int>>::iterator> toErase;

        if (leftfirst==st.end() || leftsecond==st.end()) {
            nxtleft=left;
            nxtright=right;
        }
        else {
            if (leftfirst.second<left.second) {
                nxtleft=left;
                if (right.first<*leftsecond.first) {
                    leftfirst.first=
                }
            }
            else if (leftfirst.second==left.second) {

            }
            else if (leftsecond.second<left.second && left.second<leftfirst.second) {
                toErase.push_back(leftsecond);
                nxtleft={*leftsecond.first, left.second};
            }
            else if (left.second<=leftsecond.second) {

            }

            if (*rightfirst.second<right.second) {

            }
        }
        else if (*leftfirst.first==left.first) {

        }

        else {

        }
    }




    return 0;
}
