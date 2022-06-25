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

	int n, m;
	cin >> n >> m;
	vector<int> num(n+1, 1);
	vector<bool> pos(n+1, false);
	pos[1]=true;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		if (pos[x]==true) {
			if (num[x]==1) {
				pos[x]=false;
				pos[y]=true;
			}
			else {
				pos[y]=true;
			}
		}
		num[x]--;
		num[y]++;
	}
	int ans=0;
	for (auto i:pos) {
		ans+=i;
	}
	cout << ans;

	return 0;
}
