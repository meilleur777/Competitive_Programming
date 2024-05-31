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

	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int> > ver(h, vector<int>(w, 0)), hor(h, vector<int>(w, 0));
	for (int i=0; i<h; i++) {
		int row=0;
		for (int j=0; j<w; j++) {
			if (s[i][j]=='#') {
				for (int k=0; k<row; k++) {
					ver[i][j-k-1]=row;
				}
				row=0;
			}
			else row++;
		}
		for (int k=0; k<row; k++) {
			ver[i][w-1-k]=row;
		}
	}
	for (int i=0; i<w; i++) {
		int row=0;
		for (int j=0; j<h; j++) {
			if (s[j][i]=='#') {
				for (int k=0; k<row; k++) {
					hor[j-k-1][i]=row;
				}
				row=0;
			}
			else row++;
		}
		for (int k=0; k<row; k++) {
			hor[h-1-k][i]=row;
		}
	}
	/*for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cout << hor[i][j];
		}
		cout << '\n';
	}*/
	int ans=-1;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			ans=max(ans, ver[i][j]+hor[i][j]-1);
		}
	}
	cout << ans;

	return 0;
}
