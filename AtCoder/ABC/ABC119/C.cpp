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

int ans=INF;
int N, A, B, C;
vector<int> l;

void solve(int now, int mp, int a, int b, int c) {
	if (now==N) {
		if (a==0 || b==0 || c==0) return;
		int tmp=abs(A-a)+abs(B-b)+abs(C-c)+mp-30;
		ans=min(ans, tmp);
		return;
	}
	solve(now+1, mp, a, b, c);
	solve(now+1, mp+10, a+l[now], b, c);
	solve(now+1, mp+10, a, b+l[now], c);
	solve(now+1, mp+10, a, b, c+l[now]);
}

int main() {
	init_code();

	cin >> N >> A >> B >> C;
	l.resize(N);
	rep(i, N) cin >> l[i];
	solve(0, 0, 0, 0, 0);
	cout << ans;

	return 0;
}
