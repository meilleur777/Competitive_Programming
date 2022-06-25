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

	vector<vector<int> > c(3, vector<int>(3));
	rep(i, 3) {
		rep(j, 3) {
			cin >> c[i][j];
		}
	}
	vector<int> a(3), b(3);
	for (a[0]=0; a[0]<=100; a[0]++) {
		for (a[1]=0; a[1]<=100; a[1]++) {
			for (a[2]=0; a[2]<=100; a[2]++) {
				for (int i=0; i<3; i++) {
					b[i]=c[i][i]-a[i];
				}
				bool flag=true;
				for (int i=0; i<3; i++) {
					for (int j=0; j<3; j++) {
						if (c[i][j]!=a[i]+b[j]) {
							flag=false;
						}
					}
				}
				if (flag) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";

	return 0;
}
