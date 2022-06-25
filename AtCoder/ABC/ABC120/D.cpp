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

vector<int> mem;
vector<int> parent;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	mem[a] += mem[b];
	parent[b] = a;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	mem = vector<int>(N+1, 1);
	parent.resize(N+1);
	rep(i, N) parent[i+1] = i+1;
	vector<intp> edge(M+1);
	for (int i = 1;  i <= M; i++) {
		int a, b;
		cin >> a >> b;
		edge[i] = {a, b};
	}
	vector<ll> res;
	for (int i = M; i >= 1; i--) {
		intp now = edge[i];
		int a = find(now.first), b = find(now.second);
		if (a != b) {
			res.push_back((ll)mem[a]*mem[b]);
			merge(now.first, now.second);
		}
		else {
			res.push_back(0);
		}
	}
	for (int i = res.size()-1; i > 0; i--) {
		res[i-1] += res[i];
	}
	for (int i = res.size()-1; i >= 0; i--) {
		cout << res[i] << '\n';
	}

	return 0;
}
