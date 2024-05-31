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

int n;
vector<string> s, t;

void rot() {
	vector<string> tmp(n, string(n, 'e'));
	rep(i, n) rep(j, n) tmp[n-1-j][i]=s[i][j];
	rep(i, n) rep(j, n) s[i][j]=tmp[i][j];
}

int main() {
	init_code();

	cin >> n;
	s.resize(n), t.resize(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	int txs=n, tys=n, txe=-1, tye=-1;
	rep(j, n) rep(k, n) {
		if (t[j][k]=='#') {
			txs=min(txs, j);
			tys=min(tys, k);
			txe=max(txe, j);
			tye=max(tye, k);
		}
	}
	for (int i=0; i<4; i++) {
		int sxs=n, sys=n, sxe=-1, sye=-1;
		rep(j, n) rep(k, n) {
			if (s[j][k]=='#') {
				sxs=min(sxs, j);
				sys=min(sys, k);
				sxe=max(sxe, j);
				sye=max(sye, k);
			}
		}
		if (sxe-sxs!=txe-txs || sye-sys!=tye-tys) {
			rot();
			continue;
		}
		bool flag=true;
		for (int j=0; j<n && sxs+j<=sxe && txs+j<=txe; j++) {
			if (!flag) break;
			for (int k=0; k<n && sys+k<=sye && tys+k<tye; k++) {
				if (s[j+sxs][k+sys]!=t[j+txs][k+tys]) {
					flag=false;
					break;
				}
			}
		}
		if (flag) {
			cout << "Yes";
			return 0;
		}
		rot();
	}
	cout << "No";

	return 0;
}
