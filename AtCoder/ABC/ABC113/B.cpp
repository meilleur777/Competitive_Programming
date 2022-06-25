#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	int N;
	ld T, A;
	cin >> N >> T >> A;
	int ri;
	ld rv=DBL_MAX;
	rep(i, N) {
		ld h;
		cin >> h;
		ld tmp=T-h*0.006;
		if (fabs(tmp-A)<rv) {
			rv=fabs(tmp-A);
			ri=i+1;
		}
	}
	cout << ri;

	return 0;
}
