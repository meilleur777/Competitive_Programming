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

int main() {
	init_code();

	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		vector<string> res;
		res.push_back(s);
		while (next_permutation(s.begin(), s.end())) {
			res.push_back(s);
		}
		res.erase(unique(res.begin(), res.end()), res.end());
		for (auto i : res) {
			cout << i << '\n';
		}
	}

	return 0;
}
