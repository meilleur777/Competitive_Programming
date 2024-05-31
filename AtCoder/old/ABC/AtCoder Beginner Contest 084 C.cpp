#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n;
	cin >> n;
	vector<ll> c(n-1), s(n-1), f(n-1);
	rep(i, n-1) {
		cin >> c[i] >> s[i] >> f[i];
	}	
	for (int i=0; i<n-1; i++) {
		ll now=s[i]+c[i];
		for (int j=i+1; j<n-1; j++) {
			if (now>=s[j] && now%f[j]==0) {
				now+=c[j];
			}
			else if (now<s[j]) {
				now=s[j]+c[j];
			}
			else {
				now=(now+f[j]-1)/f[j]*f[j];
				now+=c[j];
			}
		}
		cout << now << '\n';
	}
	cout << 0;

	return 0;
}
