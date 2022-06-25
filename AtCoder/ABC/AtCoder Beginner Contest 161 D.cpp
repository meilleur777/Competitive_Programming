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

	int k;
	cin >> k;
	deque<ll> dq;
	k--;
	for (int i=1; i<10; i++) dq.push_back(i);
	while (k--) {
		ll now=dq.front();
		dq.pop_front();
		if (now%10==9) {
			dq.push_back(now*10+8);
			dq.push_back(now*10+9);
		}
		else if (now%10==0) {
			dq.push_back(now*10);
			dq.push_back(now*10+1);
		}
		else {
			dq.push_back(now*10+now%10-1);
			dq.push_back(now*10+now%10);
			dq.push_back(now*10+now%10+1);
		}
	}
	cout << dq.front();

	return 0;
}
