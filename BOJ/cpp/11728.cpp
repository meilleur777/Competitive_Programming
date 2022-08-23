#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	int aa=0, bb=0;
	while (true) {
		if (aa==n && bb==m) break;
		else if (aa==n) {
			cout << b[bb] << ' ';
			bb++;
		}
		else if (bb==m) {
			cout << a[aa] << ' ';
			aa++;
		}
		else {
			if (a[aa]>b[bb]) {
				cout << b[bb] << ' ';
				bb++;
			}
			else {
				cout << a[aa] << ' ';
				aa++;
			}
		}
	}

	return 0;
}
