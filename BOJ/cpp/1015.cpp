#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int now=0;
	vector<int> ans(n);
	for (int i=1; i<=1000; i++) {
		for (int j=0; j<n; j++) {
			if (i==a[j]) {
				ans[j]=now;
				now++;
			}
		}
	}
	for (auto i:ans) cout << i << ' ';

	return 0;
}
