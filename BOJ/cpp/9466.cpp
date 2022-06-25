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

int cnt;
vector<int> A;
vector<bool> vis, chk;

void DFS(int now) {
	vis[now]=true;
	if (!vis[A[now]]) {
		DFS(A[now]);
	}
	else {
		if (!chk[A[now]]) {
			cnt++;
			int tmp=A[now];
			while (tmp!=now) {
				tmp=A[tmp];
				cnt++;
			}
		}
	}
	chk[now]=true;
}

int main() {
	init_code();

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		A.clear();
		A.resize(n+1);
		vis=chk=vector<bool>(n+1, false);
		rep(i, n) cin >> A[i+1];
		cnt=0;	
		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				DFS(i);
			}
		}
		cout << n-cnt << '\n';
	}

	return 0;
}
