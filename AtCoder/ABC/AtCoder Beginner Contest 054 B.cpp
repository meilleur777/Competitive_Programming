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

	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	rep(i, N) cin >> A[i];
	rep(i, M) cin >> B[i];
	for (int i=0; i<=N-M; i++) {
		for (int j=0; j<=N-M; j++) {
			bool flag=true;
			for (int k=0; k<M; k++) {
				if (flag==false) break;
				for (int l=0; l<M; l++) {
					if (A[i+k][j+l]!=B[k][l]) {
						flag=false;
						break;
					}
				}
			}
			if (flag==true) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}
