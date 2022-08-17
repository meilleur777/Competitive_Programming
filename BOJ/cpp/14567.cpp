#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> edge(n, vector<bool>(n, false));
	while (m--) {
		int a,b;	
		cin >> a >> b;
		a--, b--;
		edge[a][b]=true;
	}

	vector<int> ans(n, 1);
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (edge[j][i]==true) {
				ans[i]=max(ans[i], ans[j]+1);
			}
		}
	}
	for (int i=0; i<n; i++) cout << ans[i] << ' ';

	return 0;
}
