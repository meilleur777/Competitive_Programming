#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int sum=0;
    int sum2=0;
    for (int i=0; i<n; i++) {
        sum+=a[i];
        sum2+=a[i]*a[i];
    }

    int ans=INT_MAX;
    for (int j=-1; j<=1; j++) {
        int avg=sum/n+j;
        int tmp=n*avg*avg-2*avg*sum+sum2;
        ans=min(ans, tmp);
    }
    cout << ans;

    return 0;
}
