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
	vector<int> b(n+1);
	rep(i, n) cin >> b[i+1];
	vector<int> res;
	for (int i=n; i>0; i--) {
		bool flag=false;
		for (int j=i; j>0; j--) {
			if (b[j]==j) {
				b.erase(b.begin()+j);
				res.push_back(j);
				flag=true;
				break;
			}
		}
		if (!flag) {
			cout << -1;
			return 0;
		}
	}
	reverse(res.begin(), res.end());
	rep(i, n) cout << res[i] << '\n';

	return 0;
}
