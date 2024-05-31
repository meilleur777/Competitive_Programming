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

bool cpr(intp& a, intp& b) {
	if (a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<intp> v(n);
	priority_queue<intp, vector<intp>, greater<intp> > pq;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		pq.push({b, a});
	}
	int time=0;
	while (!pq.empty()) {
		int ned=pq.top().second;
		int end=pq.top().first;
		pq.pop();
		time+=ned;
		if (time>end) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}
