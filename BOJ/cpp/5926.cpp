#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> cow(n); //position, breed
    set<int> st;
    for (int i=0; i<n; i++) {
        cin >> cow[i].first >> cow[i].second;
        st.insert(cow[i].second);
    }

    sort(cow.begin(), cow.end());

    int ans=0;
    int left=-1, right=1e9+1;
    while (left+1<right) {
        int mid=(left+right)/2;

        int ptr=0;
        bool flag=false;
        map<int, int> breed;
        for (int now=0; now<n; now++) {
            while (ptr<n && cow[ptr].first-cow[now].first<=mid) {
                breed[cow[ptr].second]++;
                ptr++;
            }

            if ((int)breed.size()==(int)st.size()) {
                flag=true;
                break;
            }

            breed[cow[now].second]--;
            if (breed[cow[now].second]==0) {
                breed.erase(cow[now].second);
            }
        }

        if (flag) {
            right=mid;
            ans=mid;
        }
        else left=mid;
    }

    cout << ans;

    return 0;
}
