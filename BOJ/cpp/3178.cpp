#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<string>> v(2, vector<string>(n));
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        string preStr=s.substr(0, k);
        string sufStr=s.substr(k, k);
        reverse(sufStr.begin(), sufStr.end());
        v[0][i]=preStr, v[1][i]=sufStr;
    }

    for (auto& i:v) sort(i.begin(), i.end());

    int ans=2*k;
    for (int i=0; i<2; i++) {
        for (int j=0; j<n-1; j++) {
            int ptr=0;
            while (ptr<k && v[i][j][ptr]==v[i][j+1][ptr]) {
                ptr++;
            }
            ans+=k-ptr;
        }
    }
    cout << ans;

    return 0;
}
