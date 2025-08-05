#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n;
	cin >> n;
	vector<long long> a(n), b(n);

	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}

	sort(a.begin(), a.end(), greater<int>());

	long long ans=0;
	for (int i=0; i<n; i++) {
		ans+=a[i]*(n-i)+b[i];
	}
	cout << ans;

	return 0;
}
