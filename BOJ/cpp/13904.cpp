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

bool cpr(intp a, intp b) {
	return (a.second<b.second);
}

int main() {
	init_code();

	int N;
	cin >> N;
	vector<intp> v;
	rep(i, N) {
		int d, w;
		cin >> d >> w;
		v.push_back({w, d});
	}
	sort(v.begin(), v.end(), cpr);
	int sco=0;
	int cnt=v.back().second;
	priority_queue<intp> pq;
	while (true) {
		while (!v.empty() && v.back().second>=cnt) {
			pq.push(v.back());
			v.pop_back();
		}
		if (pq.empty()) {
			cnt--;
			if (!cnt) break;
			continue;
		}
		sco+=pq.top().first;
		pq.pop();
		cnt--;
		if (!cnt) break;
	}
	cout << sco;

	return 0;
}
