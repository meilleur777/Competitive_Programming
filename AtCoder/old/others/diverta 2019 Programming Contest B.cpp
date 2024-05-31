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

	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int cnt=0;
	for (int r=0; r<=3000; r++) {
		for (int g=0; g<=3000; g++) {
			ll tmp=N-r*R-g*G;
			if (tmp>=0 && tmp%B==0) {
				cnt++;
			}
		}
	}
	cout << cnt;	

	return 0;
}
