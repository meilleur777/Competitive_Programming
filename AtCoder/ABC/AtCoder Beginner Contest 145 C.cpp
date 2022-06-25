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
	cout << fixed;
	cout.precision(10);

	int n;
	cin >> n;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	ld ans=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			ld a=v[i].first-v[j].first;
			ld b=v[i].second-v[j].second;
			ld dis=pow(a*a+b*b, 0.5);
			ans+=2*dis/n;
		}
	}
	cout << ans;

	return 0;
}
