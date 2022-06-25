#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	int N, M;
	cin >> N >> M;
	vector<int> ind(N+1, 0);
	vector<vector<int> > edge(N+1);
	rep(i, M) {
		int k;
		cin >> k;
		vector<int> t(k);
		rep(j, k) cin >> t[j];
		for (int j=0; j<k-1; j++) {
			edge[t[j]].push_back(t[j+1]);
			ind[t[j+1]]++;
		}
	}
	queue<int> q;
	for (int i=1; i<=N; i++) {
		if (ind[i]==0) {
			q.push(i);
		}
	}
	int cnt=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		cnt++;
		for (auto i : edge[now]) {
			ind[i]--;
			if (ind[i]==0) {
				q.push(i);
			}
		}
	}
	if (cnt!=N) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}

	return 0;
}
