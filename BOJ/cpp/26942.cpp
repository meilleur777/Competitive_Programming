#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    map<string, int> nameToNum;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        nameToNum[s]=i;
    }

    vector<int> par(n);
    for (int i=0; i<n; i++) par[i]=i;
    function<int(int)> find=[&](int x) {
        if (par[x]==x) return x;
        return find(par[x]);
    };
    function<void(string, string)> merge=[&](string a, string b) {
        int aa=nameToNum[a], bb=nameToNum[b];
        int aaa=find(aa), bbb=find(bb);
        if (aaa==bbb) return;
        par[bbb]=aaa;
    };

    int m;
    cin >> m;
    while (m--) {
        string a, b;
        cin >> a >> b;
        merge(a, b);
    }

    set<int> st;
    for (int i=0; i<n; i++) {
        st.insert(find(i));
    }
    cout << (int)st.size();

    return 0;
}
