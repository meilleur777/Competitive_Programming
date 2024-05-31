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

	int h, w, k;
	cin >> h >> w >> k;
	vector<string> brd(h);
	rep(i, h) cin >> brd[i];
	vector<vector<int> > ans(h, vector<int>(w));
	vector<bool> empty(h, false);
	rep(i, h) {
		if (brd[i].find('#')==string::npos) {
			empty[i]=true;
		}
	}
	int num=0;
	for (int i=0; i<h; i++) {
		if (empty[i]) continue;
		num++;
		bool fir=true;
		for (int j=0; j<w; j++) {
			if (brd[i][j]=='#') {
				if (!fir) {
					num++;
				}
				else {
					fir=false;
				}
			}
			ans[i][j]=num;
		}
	}
	for (int i=0; i<h; i++) {
		if (empty[i]) {
			if (i==h-1) {
				ans[i]=ans[i-1];
			}
			else {
				int ptr=i+1;
				while (ptr<h && empty[ptr]) {
					ptr++;
				}
				if (ptr==h) {
					ptr=i-1;
					while (ptr>=0 && empty[ptr]) {
						ptr--;
					}
				}
				ans[i]=ans[ptr];
			}
		}
		for (auto j:ans[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}
