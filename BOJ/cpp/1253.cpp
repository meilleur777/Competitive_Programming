#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans=0;
    for (int i=0; i<n; i++) {
        int left=0, right=n-1;

        while (left<right) {
            if (a[left]+a[right]<a[i]) {
                left++;
            }
            else if (a[left]+a[right]>a[i]) {
                right--;
            }
            else {
                if (left==i) left++;
                else if (right==i) right--;
                else {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
