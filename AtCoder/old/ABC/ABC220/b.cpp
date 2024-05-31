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

	ll k;
	string a, b;
	cin >> k >> a >> b;
	ll la=0, lb=0;
	for (int i=0; i<a.size(); i++) {
		la+=pow(k, (int)a.size()-i-1)*(a[i]-'0');
	}
	for (int i=0; i<b.size(); i++) {
		lb+=pow(k, (int)b.size()-i-1)*(b[i]-'0');
	}
	cout << la*lb;

	return 0;
}
