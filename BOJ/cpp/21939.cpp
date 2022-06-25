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
	priority_queue<intp> maxpq;
	priority_queue<intp, vector<intp>, greater<intp> > minpq;
	map<int, int> minchk, maxchk;
	rep(i, N) {
		int p, l;
		cin >> p >> l;
		maxpq.push({l, p});
		minpq.push({l, p});
	}
	int M;
	cin >> M;
	while (M--) {
		string ord;
		cin >> ord;
		if (ord=="recommend") {
			int x;
			cin >> x;
			if (x==1) {
				cout << maxpq.top().second << '\n';
			}
			else {
				cout << minpq.top().second << '\n';
			}
		}
		else if (ord=="add") {
			int p, l;
			cin >> p >> l;
			maxpq.push({l, p});
			minpq.push({l, p});
		}
		else {
			int p;
			cin >> p;
			maxchk[p]++;
			minchk[p]++;
		}
		while (maxchk[maxpq.top().second]>0) {
			maxchk[maxpq.top().second]--;
			maxpq.pop();
		}
		while (minchk[minpq.top().second]>0) {
			minchk[minpq.top().second]--;
			minpq.pop();
		}
	}

	return 0;
}
