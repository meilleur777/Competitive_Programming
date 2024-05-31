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

	int a, b, k;
	cin >> a >> b >> k;
	vector<int> res;
	for (int i=a; i<a+k && i<=b; i++) {
		res.push_back(i);
	}	
	for (int i=b; i>b-k && i>=a; i--) {
		res.push_back(i);
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto i:res) cout << i << '\n';

	return 0;
}
