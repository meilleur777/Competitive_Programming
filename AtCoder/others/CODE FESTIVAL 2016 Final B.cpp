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

	int n;
	cin >> n;
	int t=1;	
	while (true) {
		if (t*(t+1)/2>=n) break;
		t++;
	}
	vector<int> res;
	for (int i=t; i>=1; i--) {
		if (i<=n) {
			n-=i;
			res.push_back(i);
		}
	}
	reverse(res.begin(), res.end());
	for (auto i:res) cout << i << '\n';

	return 0;
}
