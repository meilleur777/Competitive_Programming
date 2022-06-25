#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	auto chk=[&](vector<int> www) {
		if (www.size()==1) {
			cout << www[0];
			exit(0);
		}
		for (int i=0; i<(int)www.size()-1; i++) {
			if (www[i]==www[i+1]) return;
			if (www[i+1]==0) {
				if (i+2<(int)www.size()) {
					rep(j, 3) {
						if (j+1!=www[i] && j+1!=www[i+2]) {
							www[i+1]=j+1;
						}
					}
				}
				else {
					rep(j, 3) {
						if (j+1!=www[i]) {
							www[i+1]=j+1;
							break;
						}
					}
				}
			}
		}
		rep(i, n) cout << www[i] << ' ';
		exit(0);
	};
	if (a[0]==0) {
		rep(i, 3) {
			vector<int> b=a;
			b[0]=i+1;
			chk(b);
		}
	}
	else {
		chk(a);
	}
	cout << -1;

	return 0;
}
