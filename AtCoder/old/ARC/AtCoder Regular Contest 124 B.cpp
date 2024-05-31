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
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	set<int> s;
	for (int i=0; i<n; i++) {
		int tmp=a[0]^b[i];
		bool flag=true;
		multiset<int> ms;
		rep(k, n) ms.insert(b[k]);
		for (int j=0; j<n; j++) {
			auto fin=ms.find(a[j]^tmp);
			if (fin==ms.end()) {
				flag=false;
				break;
			}
			else ms.erase(fin);
		}
		if (flag) s.insert(tmp);
	}
	cout << s.size() << '\n';
	for (auto i:s) cout << i << '\n';

	return 0;
}
