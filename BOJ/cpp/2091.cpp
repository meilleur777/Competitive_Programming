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

	int x, a, b, c, d;
	cin >> x >> a >> b >> c >> d;
	b=min(b, x/5);
	c=min(c, x/10);
	d=min(d, x/25);
	int mx=-1;
	int ans[4]={0};
	for (int i=0; i<=d; i++) {
		for (int j=0; j<=c; j++) {
			if (25*i+10*j>x) break;
			for (int k=0; k<=b; k++) {
				int tmp=25*i+10*j+5*k;
				if (tmp>x) break;
				if (a>=x-tmp) {
					int t=x-tmp+k+j+i;
					if (t>mx) {
						mx=t;
						ans[0]=x-tmp, ans[1]=k, ans[2]=j, ans[3]=i;
					}
				}
			}
		}
	}	
	rep(i, 4) cout << ans[i] << ' ';

	return 0;
}
