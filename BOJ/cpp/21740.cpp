#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v(n);

    function<string(const string&)> conv=[&](const string& a) {
        string aa;
        for (int i=(int)a.size()-1; i>=0; i--) {
            char c=a[i];
            if (c=='6') aa+='9';
            else if (c=='9') aa+='6';
            else aa+=c;
        }
        return aa;
    };
    rep(i, n) {
        cin >> v[i];
        v[i]=conv(v[i]);
    }

    string big="0";
    rep(i, n) {
        if (v[i].size()>big.size() || (v[i].size()==big.size() && v[i]>big)) big=v[i];
    }
    v.push_back(big);
    sort(v.begin(), v.end(), [&](const string& a, const string& b) {
        return a+b<b+a;
    });
    for (auto i:v) {
        cout << conv(i);
    }

    return 0;
}
