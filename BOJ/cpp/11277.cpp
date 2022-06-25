#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<intp> a(m);
	rep(i, m) cin >> a[i].first >> a[i].second;
	for (int i=0; i<(1<<n); i++) {
		vector<bool> sel(n);
		rep(j, n) sel[j]=(i&(1<<j));
		bool flag=true;
		rep(j, m) {
			bool fir=sel[abs(a[j].first)-1];
			bool sec=sel[abs(a[j].second)-1];
			if (a[j].first<0) fir=!fir;
			if (a[j].second<0) sec=!sec;
			bool tmp=fir||sec;
			if (!tmp) {
				flag=false;
				break;
			}
		}
		if (flag) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
