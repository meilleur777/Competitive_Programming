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

ll gcd(ll a, ll b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	init_code();

	ll n, s;
	cin >> n >> s;
	vector<ll> x(n);
	rep(i, n) cin >> x[i] ;
	x.push_back(s);
	sort(x.begin(), x.end());
	vector<ll> dis;
	for (int i=0; i<n; i++) {
		dis.push_back(x[i+1]-x[i]);
	}
	ll g=dis[0];
	for (int i=1; i<(int)dis.size(); i++) {
		g=gcd(g, dis[i]);
	}
	cout << g;

	return 0;
}
