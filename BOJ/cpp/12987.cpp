#include <bits/stdc++.h>
using namespace std;

int n, mod;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ret(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                ret[i][j]+=a[i][k]*b[k][j];
                ret[i][j]%=mod;
            }
        }
    }

    return ret;
}

vector<vector<int>> power(vector<vector<int>> base, int exp) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) ret[i][i]=1;

    while (exp) {
        if (exp%2==1) {
            ret=mul(ret, base);
        }
        base=mul(base, base);
        exp/=2;
    }

    return ret;
}

vector<vector<int>> sum(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> ret(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ret[i][j]=(a[i][j]+b[i][j])%mod;
        }
    }

    return ret;
}

vector<vector<int>> powerSum(vector<vector<int>> base, int exp) {
    if (exp==1) return base;

    vector<vector<int>> tmp=power(base, exp/2);
    for (int i=0; i<n; i++) {
        tmp[i][i]=(tmp[i][i]+1)%mod;
    }
    
    vector<vector<int>> ret=mul(tmp, powerSum(base, exp/2));
    if (exp%2==1) ret=sum(ret, power(base, exp));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k;
    cin >> n >> k >> mod;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            a[i][j]=(a[i][j]%mod+mod)%mod;
        }
    }

    vector<vector<int>> res=powerSum(a, k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
