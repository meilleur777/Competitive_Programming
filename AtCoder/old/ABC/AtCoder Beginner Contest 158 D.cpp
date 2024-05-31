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

	string s;
	cin >> s;
	int q;
	cin >> q;
	deque<char> dq;
	for (auto i:s) {
		dq.push_back(i);
	}
	bool rev=false;
	while (q--) {
		int t;
		cin >> t;
		if (t==1) {
			rev=!rev;
		}
		else {
			int f;
			char c;
			cin >> f >> c;
			if (f==1) {
				if (rev) dq.push_back(c);
				else dq.push_front(c);
			}
			else {
				if (rev) dq.push_front(c);
				else dq.push_back(c);
			}
		}
	}	
	if (rev) {
		reverse(dq.begin(), dq.end());
	}
	for (auto i:dq) cout << i;

	return 0;
}
