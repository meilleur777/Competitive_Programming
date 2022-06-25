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

int dy[8]={0, 0, 1, 1, 1, -1, -1, -1};
int dx[8]={1, -1, -1, 0, 1, -1, 0, 1};

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	vector<string> brd(h);
	rep(i, h) cin >> brd[i];
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (brd[i][j]=='#') cout << '#';
			else {
				int cnt=0;
				for (int k=0; k<8; k++) {
					int ny=i+dy[k], nx=j+dx[k];
					if (ny>=h || ny<0 || nx>=w || nx<0) continue;
					if (brd[ny][nx]=='#') cnt++;
				}
				cout << cnt;
			}
		}
		cout << '\n';
	}

	return 0;
}
