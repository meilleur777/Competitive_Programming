#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	vector<bool> v(1000000+1, false);
	vector<int> cnt(1000000+1, 0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		v[a[i]]=true;
	}
	for (int i=1; i<=1000000; i++) {
		if (!v[i]) continue;
		for (int j=i*2; j<=1000000; j+=i) {
			if (!v[j]) continue;
			cnt[i]++;
			cnt[j]--;
		}
	}
	for (int i=0; i<n; i++) {
		cout << cnt[a[i]] << ' ';
	}

	return 0;
}
