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
	map<int, ll> m;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		m[a]++;
		m[a+b]--;
	}
	vector<int> cnt(n+1, 0);
	int now=0;
	int las=0;
	for (auto [a, b]:m) {
		cnt[now]+=a-las;
		now+=b;
		las=a;
	}
	for (int i=1; i<=n; i++) {
		cout << cnt[i] << ' ';
	}

	return 0;
}
