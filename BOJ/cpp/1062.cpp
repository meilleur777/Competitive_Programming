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

int N, K;
int ans=-1;
vector<string> W;

void solve(int now, ll can) {
	if (now=='c'-'a' || now=='n'-'a' || now=='t'-'a' || now=='i'-'a') {
		solve(now+1, can);
		return;
	}
	if (now==26) {
		if (can!=0 && __builtin_popcount(can)==K+5) {
			int cnt=0;
			for (int i=0; i<N; i++) {
				bool flag=true;
				for (int j=4; j<W[i].size()-4; j++) {
					int tmp=W[i][j]-'a';
					if (!(can&(1LL<<tmp))) {
						flag=false;
						break;
					}
				}
				if (flag) cnt++;
			}
			ans=max(ans, cnt);
		}
		return;
	}
	solve(now+1, can);
	solve(now+1, can|(1LL<<now));
}

int main() {
	init_code();

	cin >> N >> K;
	W.resize(N);
	rep(i, N) cin >> W[i];
	K-=5;
	if (K<0) {
		cout << 0;
		return 0;
	}
	string tmp("antic");
	ll sta=0;
	for (auto i : tmp) {
		sta|=(1LL<<(i-'a'));
	}
	solve(1, sta);
	cout << ans;

	return 0;
}
