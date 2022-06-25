#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int A, B;
	cin >> A >> B;
	int m;
	cin >> m;
	vector<ll> C(m);
	rep(i, m) cin >> C[i];
	reverse(C.begin(), C.end());
	ll dec=0;
	for (int i=0; i<m; i++) {
		dec+=(ll)pow(A, i)*C[i];
	}
	vector<int> ans;
	ll temp=1;
	while (temp<=dec) {
		temp*=B;
	}
	temp/=B;
	while (temp) {
		ans.push_back(dec/temp);
		dec%=temp;
		temp/=B;
	}
	for (auto i : ans) {
		cout << i << ' ';
	}

	return 0;
}
