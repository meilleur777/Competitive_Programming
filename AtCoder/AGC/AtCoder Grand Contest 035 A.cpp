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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> m;
	rep(i, n) {
		m[a[i]]++;
	}
	vector<int> v;
	for (auto [a, b]:m) {
		v.push_back(b);
	}
	if (v.size()==1) {
		if (m[0]==n) {
			cout << "Yes";
			return 0;
		}
	}
	else if (v.size()==2) {
		if (n%3==0 && ((v[0]==n/3 && v[1]==2*n/3) || (v[0]==2*n/3 && v[1]==n/3))) {
			cout << "Yes";
			return 0;
		}
	}
	else if (v.size()==3) {
		if (v[0]==v[1] && v[1]==v[2] && v[2]==v[0]) {
			int tmp=0;
			for (auto [a, b]:m) {
				tmp^=a;
			}
			if (tmp==0) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}
