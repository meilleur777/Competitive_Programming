#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

/*0->empty, 1->bulb, 2->block, 3->illum*/
vector<vector<int> > brd;

int main() {
	init_code();

	int H, W, N, M;
	cin >> H >> W >> N >> M;
	brd=vector<vector<int> >(H+1, vector<int>(W+1, 0));
	rep(i, N) {
		int a, b;
		cin >> a >> b;
		brd[a][b]=1;
	}
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		brd[a][b]=2;
	}
	for (int i=1; i<=H; i++) {
		bool sta=false;
		for (int j=1; j<=W; j++) {
			if (sta) {
				if (brd[i][j]==0) {
					brd[i][j]=3;
				}
				else if (brd[i][j]==2) {
					sta=false;
				}
			}
			else {
				if (brd[i][j]==1) {
					sta=true;
				}
			}
		}
		sta=false;
		for (int j=W; j>=0; j--) {
			if (sta) {
				if (brd[i][j]==0) {
					brd[i][j]=3;
				}
				else if (brd[i][j]==2) {
					sta=false;
				}
			}
			else {
				if (brd[i][j]==1) {
					sta=true;
				}
			}
		}
	}
	for (int i=1; i<=W; i++) {
		bool sta=false;
		for (int j=1; j<=H; j++) {
			if (sta) {
				if (brd[j][i]==0) {
					brd[j][i]=3;
				}
				else if (brd[j][i]==2) {
					sta=false;
				}
			}
			else {
				if (brd[j][i]==1) {
					sta=true;
				}
			}
		}
		sta=false;
		for (int j=H; j>=1; j--) {
			if (sta) {
				if (brd[j][i]==0) {
					brd[j][i]=3;
				}
				else if (brd[j][i]==2) {
					sta=false;
				}
			}
			else {
				if (brd[j][i]==1) {
					sta=true;
				}
			}
		}
	}
	int ans=0;
	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			if (brd[i][j]==1 || brd[i][j]==3) {
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}
