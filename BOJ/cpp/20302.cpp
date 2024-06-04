#include <bits/stdc++.h>
using namespace std;

void eratosthenes(int bound, vector<int>& spf) {
    spf=vector<int>(bound+1, 1);
    spf[0]=0;

    for (int i=2; i<=bound; i++) {
        if (spf[i]!=1) continue;

        for (int j=i; j<=bound; j+=i) {
            if (spf[j]!=1) continue;
            spf[j]=i;
        }
    }
}

void factorization(int num, vector<int>& cnt, const vector<int>& spf, bool isMul) {
    if (num==0) {
        cnt[0]++;
        return;
    }

    while (num!=1) {
        if (isMul) cnt[spf[num]]++;
        else cnt[spf[num]]--;
        num/=spf[num];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> spf;
    const int bound=1e5;
    eratosthenes(bound, spf);

    int n;
    cin >> n;

    vector<int> cnt(bound+1, 0);
    for (int i=0; i<n; i++) {
        int a;
        char c='*';
        if (i>0) cin >> c;
        cin >> a;
        a=abs(a);

        if (a==0) {
            cout << "mint chocolate";
            return 0;
        }

        if (c=='*') factorization(a, cnt, spf, true);
        else factorization(a, cnt, spf, false);
    }

    int mn=*min_element(cnt.begin(), cnt.end());
    if (mn<0) cout << "toothpaste";
    else cout << "mint chocolate";

    return 0;
}
