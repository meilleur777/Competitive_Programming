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

	int n, k;
	cin >> n >> k;
	map<int, int> m;
	map<int, int> on;
	int now=0;
	rep(i, k) {
		int a;
		cin >> a;
		if (m.count(a)==0) {
			if (now==n) {
				int mn=INF;
				for (auto [p, q]:m) {
					if (mn>q) {
						mn=q;
					}
				}
				int mi, me=INF;
				for (auto [p, q]:on) {
					if (m[p]==mn && q<me) {
						me=q;
						mi=p;
					}
				}
				m.erase(m.find(mi));
				on.erase(on.find(mi));
			}
			else now++;
			on[a]=i;
		}
		m[a]++;
	}
	for (auto [a, b]:m) {
		cout << a << ' ';
	}

	return 0;
}
