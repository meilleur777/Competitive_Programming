#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

int main() {
	init_code();

	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	int now=0;
	int sta=-1;
	vector<int> rop;
	vector<bool> vis(n, false);
	while (true) {
		if (vis[now]) {
			sta=now;
			break;
		}
		vis[now]=true;
		rop.push_back(now);
		now=a[now];
	}
	int her=-1;
	// cout << sta << ' ';
	for (int i=0; i<rop.size(); i++) {
		if (rop[i]==sta) {
			her=i;
			break;
		}
	}
	int siz=rop.size()-her;
	// cout << her << ' ' << siz << ' ';
	if (k<rop.size()) cout << rop[k]+1;
	else {
		k-=her;
		k%=siz;
		cout << rop[her+k]+1;
	}

	return 0;
}
