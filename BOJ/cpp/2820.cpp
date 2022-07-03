#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<ll> segtree;
vector<ll> lazy;

void lazyupdate(int node, int start, int end) {
	if (!lazy[node]) return;
	segtree[node]+=(end-start+1)*lazy[node];
	if (start!=end) {
		lazy[node*2+1]+=lazy[node];
		lazy[node*2+2]+=lazy[node];
	}
	lazy[node]=0;
}

void update(int node, int start, int end, int left, int right, ll value) {
	lazyupdate(node, start, end);
	if (end<left || right<start) return;
	if (left<=start && end<=right) {
		segtree[node]+=(end-start+1)*value;
		if (start!=end) {
			lazy[node*2+1]+=value;
			lazy[node*2+2]+=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update(node*2+1, start, mid, left, right, value);
	update(node*2+2, mid+1, end, left, right, value);
	segtree[node]=segtree[node*2+1]+segtree[node*2+2];
}

ll getsum(int node, int start, int end, int index) {
	lazyupdate(node, start, end);
	if (end<index || index< start) return 0;
	if (start==index && end==index) {
		return segtree[node];
	}
	int mid=(start+end)/2;
	ll leftsum=getsum(node*2+1, start, mid, index);
	ll rightsum=getsum(node*2+2, mid+1, end, index);
	return leftsum+rightsum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;	

	int height=ceil(log2(n))+1;
	segtree=vector<ll>((1<<height), 0);
	lazy=segtree;

	vector<int> num(n);

	vector<int> sta(n);
	cin >> sta[0];

	vector<vector<int>> edge(n);
	rep(i, n-1) {
		int b;
		cin >> sta[i+1];
		cin >> b;
		b--;
		edge[b].push_back(i+1);
	}

	int cnt=0;
	vector<intp> range(n, {-1, -1});
	function<void(int)> dfs=[&](int now) {
		num[now]=cnt++;
		if (edge[now].empty()) return;
		range[now].first=cnt;
		for (auto nxt:edge[now]) {
			dfs(nxt);
		}
		range[now].second=cnt-1;
	};
	dfs(0);

	rep(i, n) {
		update(0, 0, n-1, num[i], num[i], sta[i]);
	}

	while (m--) {
		char c;
		cin >> c;
		if (c=='p') {
			int a, x;
			cin >> a >> x;
			a--;
			if (range[a].first==-1) continue;
			update(0, 0, n-1, range[a].first, range[a].second, x);
		}
		else {
			int a;
			cin >> a;
			a--;
			cout << getsum(0, 0, n-1, num[a]) << '\n';
		}
	}

	return 0;
}
