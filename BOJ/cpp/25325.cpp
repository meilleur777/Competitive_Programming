#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	map<string, int> mp;
	rep(i, n) {
		string s;
		cin >> s;
		mp[s]=0;
	}

	string t;
	while (cin >> t) {
		mp[t]++;
	}

	vector<pair<string, int>> v;
	for (auto [a, b]:mp) {
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
		if (a.second==b.second) return a.first<b.first;
		return a.second>b.second;
	});

	for (auto a:v) {
		cout << a.first << ' ' << a.second << '\n';
	}

	return 0;
}
