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

int n;

void sol(string now, char mx) {
	if (now.size()==n) {
		cout << now << '\n';
		return;
	}
	for (int i=0; i<=mx-'a'+1; i++) {
		sol(now+char(i+'a'), max(mx, char(i+'a')));
	}
}

int main() {
	init_code();

	cin >> n;
	sol("", 'a'-1);

	return 0;
}
