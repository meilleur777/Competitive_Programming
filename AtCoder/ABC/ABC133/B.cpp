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

	int N, D;
	cin >> N >> D;
	vector<vector<double> > A(N, vector<double>(D));
	for (int i=0; i<N; i++) {
		for (int j=0; j<D; j++) {
			cin >> A[i][j];
		}
	}
	int ans=0;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			double tmp=0;
			for (int k=0; k<D; k++) {
				tmp+=(double)pow(A[i][k]-A[j][k], 2);
			}
			double sq=(double)sqrt(tmp);
			if ((int)sq==sq) ans++;
		}
	}
	cout << ans;

	return 0;
}
