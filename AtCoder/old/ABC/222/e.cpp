#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const ll mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m);
	rep(i, m) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> edge(n);
	vector<intp> e(n-1);
	rep(i, n-1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
		e[i]={u, v};
	}
	vector<vector<ll>> cnt(n, vector<ll>(n, 0));
	for (int i=0; i<m-1; i++) {
		int s=a[i], u=a[i+1];
		queue<int> q;
		q.push(s);
		vector<int> pi(n, -1);
		pi[s]=s;
		while (!q.empty()) {
			int now=q.front();
			q.pop();
			if (now==u) break;
			for (auto j:edge[now]) {
				if (pi[j]==-1) {
					pi[j]=now;
					q.push(j);
				}
			}
		}
		int tmp=u;
		while (true) {
			if (tmp==s) break;
			cnt[tmp][pi[tmp]]++;
			cnt[pi[tmp]][tmp]++;
			tmp=pi[tmp];
		}
	}
	vector<ll> b;
	ll sum=0;
	for (int i=0; i<n-1; i++) {
		b.push_back(cnt[e[i].first][e[i].second]);
		sum+=cnt[e[i].first][e[i].second];
	}
	vector<vector<ll>> dp(n-1, vector<ll>(sum+1, 0));
	dp[0][0]=1;
	dp[0][b[0]]++;
	for (int i=1; i<n-1; i++) {
      	for (int j=0; j<=sum; j++) {
            dp[i][j]+=dp[i-1][j];
        }
		for (int j=sum-b[i]; j>=0; j--) {
			dp[i][j+b[i]]+=dp[i-1][j];
			dp[i][j+b[i]]%=mod;
		}
	}
	int ans=sum-k;
	if (ans<0 || ans/2>sum || ans%2) cout << 0;
	else cout << dp[n-2][ans/2];

	return 0;
}
