#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&](const pair<long long, long long>& p, 
                                 const pair<long long, long long>& q) -> bool {
        return p.second*q.first>p.first*q.second;
    });

    long long sumW=0;
    long long sumS=0;
    int ptr=0;
    while (ptr<n && sumW+a[ptr].first<=m) {
        sumW+=a[ptr].first;
        sumS+=a[ptr].second;
        ptr++;
    }

    long long up, down;
    if (sumW==m) {
        up=sumS;
        down=1;
    }
    else {
        up=(m-sumW)*a[ptr].second+sumS*a[ptr].first;
        down=a[ptr].first;
    }

    long long tmp=min(up, down);
    for (long long i=2; i<=tmp; i++) {
        while (up%i==0 && down%i==0) {
            up/=i;
            down/=i;
        }
    }

    cout << up << "/" << down << '\n';  

    return 0;
}
