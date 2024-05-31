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
	vector<vector<bool> > edge(N+1, vector<bool>(N+1, false));
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		edge[a][b]=true;
		edge[b][a]=true;
	}
	vector<int> v;
	for (int i=1; i<=N; i++) {
		v.push_back(i);
	}
	int ans=0;
	do {
		if (v[0]!=1) continue;
		bool ok=true;
		for (int i=0; i<N-1; i++) {
			if (edge[v[i]][v[i+1]]==false) {
				ok=false;
				break;
			}
		}
		if (ok) ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;

	return 0;
}
