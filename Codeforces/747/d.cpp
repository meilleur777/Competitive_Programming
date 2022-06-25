#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<int> vis;
vector<vector<pair<int, bool>>> edge;

int p, q;
bool flag=true;

void dfs(int now, int col) {
	vis[now]=col;
	p+=col;
	q++;
	for (auto i:edge[now]) {
		if (vis[i.first]==-1) {
			if (i.second) dfs(i.first, col);
			else dfs(i.first, (col+1)%2);
		}
		else {
			if (!(i.second==(col==vis[i.first]))) {
				flag=false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		edge.clear();
		edge.resize(n);
		vis=vector<int>(n, -1);
		rep(i, m) {
			int a, b;
			string c;
			cin >> a >> b >> c;
			a--, b--;
			bool d=(c=="crewmate");
			edge[a].push_back({b, d});
			edge[b].push_back({a, d});
		}
		int ans=0;
		flag=true;
		for (int i=0; i<n; i++) {
			p=0, q=0;
			if (vis[i]==-1) {
				dfs(i, 0);
			}
			ans+=max(p, q-p);
		}
		if (flag) cout << ans << '\n';
		else cout << "-1\n";
	}

	return 0;
}
