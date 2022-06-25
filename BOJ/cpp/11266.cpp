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

int root;
int num=1;
vector<bool> cut;
vector<int> vis;
vector<vector<int> > edge;

int DFS(int s) {
	vis[s]=num++;
	int ret=vis[s];
	bool flag=false;
	int cnt=0;
	for (auto i : edge[s]) {
		if (vis[i]==0) {
			cnt++;
			int tmp=DFS(i);
			if (root!=s && tmp>=vis[s]) {
				cut[s]=true;
			}
			ret=min(ret, tmp);
		}
		else {
			ret=min(ret, vis[i]);
		}
	}
	if (root==s && cnt>1) {
		cut[s]=true;
	}
	return ret;
}

int main() {
	init_code();

	int V, E;
	cin >> V >> E;
	edge.resize(V+1);	
	vis=vector<int>(V+1, 0);
	cut=vector<bool>(V+1, false);
	rep(i, E) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i=1; i<=V; i++) {
		if (vis[i]==0) {	
			root=i;
			DFS(i);
		}
	}
	int cnt=0;
	vector<int> res;
	for (int i=1; i<=V; i++) {
		if (cut[i]==true) {
			res.push_back(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (auto i : res) {
		cout << i << ' ';
	}

	return 0;
}
