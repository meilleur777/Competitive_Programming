#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end(), greater<ll>());
	ll sum=0;
	int ptr=0;
	while (ptr<n && ptr*(sum+a[ptr])>=(ptr-1)*sum) {
		sum+=a[ptr];
		ptr++;
	}
	sum*=ptr;
	for (int i=ptr; i<n; i++) sum+=a[i];
	cout << sum;

	return 0;
}
