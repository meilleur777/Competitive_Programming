#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int dy[]={0, 0, 1, 1, 1, -1, -1, -1};
int dx[]={1, -1, 1, 0, -1, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	vector<string> ans(n, string(n, '.'));	
	bool flag=false;
	rep(i, n) {
		string t;
		cin >> t;
		rep(j, n) {
			if (t[j]=='x') {
				if (a[i][j]=='*') flag=true;
				else {
					int cnt=0;
					rep(d, 8) {
						int ny=i+dy[d], nx=j+dx[d];
						if (ny>=n || ny<0 || nx>=n || ny<0) continue;
						cnt+=a[ny][nx]=='*';
					}
					ans[i][j]=char(cnt+'0');
				}
			}
		}
	}
	if (flag) {
		rep(i, n) rep(j, n) {
			if (a[i][j]=='*') ans[i][j]='*';
		}
	}
	rep(i, n) cout << ans[i] << '\n';

	return 0;
}
