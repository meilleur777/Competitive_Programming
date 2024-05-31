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

	string x;
	cin >> x;
	deque<char> dq;
	for (int i=0; i<x.size(); i++) {
		if (dq.empty()) {
			dq.push_back(x[i]);
		}
		else {
			if (x[i]=='T') {
				if (dq.back()=='S') dq.pop_back();
				else dq.push_back('T');
			}
			else dq.push_back('S');
		}
	}
	cout << dq.size();

	return 0;
}
