#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];

    //alphabet, assigned integer, value, shouldn't be zero
    vector<tuple<char, int, long long, bool>> v(10);
    for (int i=0; i<10; i++) {
        get<0>(v[i])=char('A'+i);
        get<1>(v[i])=-1;
        get<2>(v[i])=0;
        get<3>(v[i])=false;
    }
    for (int i=0; i<n; i++) {
        long long tmp=1;
        for (int j=(int)s[i].size()-1; j>=0; j--) {
            get<2>(v[s[i][j]-'A'])+=tmp;
            tmp*=10;
        }
        get<3>(v[s[i][0]-'A'])=true;
    }

    sort(v.begin(), v.end(), 
        [&](const tuple<char, int, long long, bool>& p, 
            const tuple<char, int, long long, bool>& q) -> bool {
            return get<2>(p)<get<2>(q);
    });


    for (int num=0; num<10; num++) {
        for (int now=0; now<10; now++) {
            if (get<1>(v[now])!=-1) continue;
            if (num==0 && get<3>(v[now])==true) continue;
            get<1>(v[now])=num;
            break;
        }
    }

    long long ans=0;
    for (int i=0; i<10; i++) {
        ans+=get<2>(v[i])*get<1>(v[i]);
    }
    cout << ans;

    return 0;
}
