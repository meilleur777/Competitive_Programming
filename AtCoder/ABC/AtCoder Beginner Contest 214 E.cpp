#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
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

bool cpr(intp& a, intp& b) {
	return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		set<int> s;
		vector<intp> v;
		int N;
		cin >> N;
		rep(i, N) {
			int l, r;
			cin >> l >> r;
			v.push_back({l, r});
		}
		sort(v.begin(), v.end(), cpr);
		int cnt = 0;
		for (intp i : v) {
			for (int j = i.first; j <= i.second; j++) {
				if (s.find(j) == s.end()) {
					s.insert(j);
					cnt++;
					break;
				}
			}
		}
		if (cnt == N) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
