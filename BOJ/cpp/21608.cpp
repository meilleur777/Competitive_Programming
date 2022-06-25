#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n*n);
	vector<set<int>> a(n*n);
	rep(i, n*n) {
		cin >> v[i];
		rep(j, 4) {
			int b;
			cin >> b;	
			a[v[i]-1].insert(b);
		}
	}
	vector<vector<int>> brd(n, vector<int>(n, 0));
	int dy[]={0, 0, -1, 1};
	int dx[]={1, -1, 0, 0};
	for (int i=0; i<n*n; i++) {
		vector<vector<intp>> now(n, vector<intp>(n));
		rep(j, n) rep(k, n) {
			if (brd[j][k]) continue;
			int emt=0, lot=0;
			rep(d, 4) {
				int ny=j+dy[d], nx=k+dx[d];
				if (ny>=n || ny<0 || nx>=n || nx<0) continue;
				emt+=brd[ny][nx]==0;
				lot+=a[v[i]-1].find(brd[ny][nx])!=a[v[i]-1].end();
			}
			now[j][k]={lot, emt};
		}
		intp tmp={0, 0};
		rep(j, n) rep(k, n) if (!brd[j][k]) tmp=max(tmp, now[j][k]);
		bool flag=false;
		rep(j, n) {
			if (flag) break;
			rep(k, n) {
				if (!brd[j][k] && tmp==now[j][k]) {
					brd[j][k]=v[i];
					flag=true;
					break;
				}
			}
		}
	}
	int ans=0;
	rep(j, n) rep(k, n) {
		int lot=0;
		rep(d, 4) {
			int ny=j+dy[d], nx=k+dx[d];
			if (ny>=n || ny<0 || nx>=n || nx<0) continue;
			lot+=a[brd[j][k]-1].find(brd[ny][nx])!=a[brd[j][k]-1].end();
		}
		if (lot) ans+=(int)pow(10, lot-1);
	}
	cout << ans;

	return 0;
}
