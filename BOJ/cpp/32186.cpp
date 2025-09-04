#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	long long ans=0;

	for (int i=0; i<n/2; i++) {
		long long src=min(a[i], a[n-1-i]);
		long long tgt=max(a[i], a[n-1-i]);

		long long trial1=tgt-(src+(tgt-src)/k*k)+(tgt-src)/k;
		long long trial2=(src+(tgt-src+k-1)/k*k)-tgt+(tgt-src+k-1)/k;

		ans+=min(trial1, trial2);
	}

	cout << ans;

	return 0;
}
