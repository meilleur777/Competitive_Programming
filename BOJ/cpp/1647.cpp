#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

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

vector<int> parent;
vector<pair<int, pair<int, int> > > edges;

bool cpr(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
	return (a.second.second < b.second.second);
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[a] = b;	
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;

	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		edges.push_back({A, {B, C}});
	}
	sort(edges.begin(), edges.end(), cpr);

	int ans = 0, high = -1;
	for (auto i : edges) {
		int a = find(i.first);
		int b = find(i.second.first);
		int c = i.second.second;

		if (a != b) {
			merge(a, b);
			ans += c;
			high = max(high, c);
		}
	}
	cout << ans - high << '\n';
}
