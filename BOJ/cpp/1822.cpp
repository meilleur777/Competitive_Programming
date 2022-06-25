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

	int a, b;
	cin >> a >> b;
	set<int> s;
	rep(i, a) {
		int x;
		cin >> x;
		s.insert(x);
	}
	rep(i, b) {
		int x;
		cin >> x;
		if (s.count(x)) {
			s.erase(s.find(x));
		}
	}
	cout << s.size() << '\n';
	for (auto i:s) {
		cout << i << ' ';
	}

	return 0;
}
