#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int parent[501];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[a] = b;
}

int main() {
	fast_io;
	cout << fixed;
	cout.precision(10);

	int C;
	cin >> C;
	while (C--) {
		int N, M;
		cin >> N >> M;
		vector<pair<ld, intp> > edges;
		vector<int> X(N), Y(N);
		rep(i, N) parent[i] = i;
		rep(i, N) cin >> X[i];
		rep(i, N) cin >> Y[i];
		rep(i, M) {
			int a, b;
			cin >> a >> b;
			edges.push_back({0.0, {a, b}});
		}
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				ld d = sqrt((ld)pow((ld)X[i]-X[j], 2)+(ld)pow((ld)Y[i]-Y[j], 2));
				edges.push_back({d, {i, j}});
			}
		}
		sort(edges.begin(), edges.end());
		ld ans = 0;
		for (auto i : edges) {
			int u = i.second.first;
			int v = i.second.second;
			ld c = i.first;
			if (find(u) != find(v)) {
				ans += c;
				merge(u, v);
			}
		}
		cout << ans << '\n';
	}	

	return 0;
}
