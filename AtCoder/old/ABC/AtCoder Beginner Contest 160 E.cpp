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

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> p(a), q(b), r(c);
	priority_queue<intp> pq;
	/*0->red, 1->green, 2->colorless*/
	rep(i, a) {
		int o;
		cin >> o;
		pq.push({o, 0});
	}
	rep(i, b) {
		int o;
		cin >> o;
		pq.push({o, 1});
	}
	rep(i, c) {
		int o;
		cin >> o;
		pq.push({o, 2});
	}
	int cnt[3]={0};
	ll ans=0;
	while (true) {
		cnt[pq.top().second]++;
		ans+=pq.top().first;
		pq.pop();
		if (cnt[0]==x || cnt[1]==y || cnt[0]+cnt[1]+cnt[2]==x+y) {
			break;
		}
	}
	if (cnt[0]==x) {
		int tmp=y-(cnt[1]+cnt[2]);
		while (true) {
			if (pq.top().second!=0) {
				ans+=pq.top().first;
				tmp--;
				if (tmp==0) break;
			}
			pq.pop();
		}
	}
	else if (cnt[1]==y) {
		int tmp=x-(cnt[0]+cnt[2]);
		while (true) {
			if (pq.top().second!=1) {
				ans+=pq.top().first;
				tmp--;
				if (tmp==0) break;
			}
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}
