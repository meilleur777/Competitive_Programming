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

	string a, b;
	cin >> a >> b;
	auto sol=[&](string a) {
		int sum=0;
		for (auto i:a) {
			sum+=i-'0';
		}
		return sum;
	};
	cout << max(sol(a), sol(b));

	return 0;
}
