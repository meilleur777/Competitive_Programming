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

vector<vector<int> > A;

int main() {
	init_code();

	int N, L;
	cin >> N >> L;
	A=vector<vector<int> >(N, vector<int>(N));
	rep(i, N) rep(j, N) cin >> A[i][j];
	int ans=0;
	for (int i=0; i<N; i++) {
		bool flag=true;
		int row=1, memo=A[i][0];
		for (int j=1; j<N; j++) {
			if (memo==A[i][j]) {
				row++;
			}	
			else if (memo==A[i][j]-1) {
				if (row>=L) {
					memo++;
					row=1;
				}
				else {
					flag=false;
					break;
				}
			}
			else if (memo==A[i][j]+1) {
				int sta=j+1, tro=1;
				while (sta<N && A[i][j]==A[i][sta] && tro<L) {
					sta++;
					tro++;
				}
				if (tro>=L) {
					j+=L-1;
					row=0;
					memo--;
				}
				else {
					flag=false;
					break;
				}
			}
			else {
				flag=false;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	for (int i=0; i<N; i++) {
		bool flag=true;
		int row=1, memo=A[0][i];
		for (int j=1; j<N; j++) {
			if (memo==A[j][i]) {
				row++;
			}	
			else if (memo==A[j][i]-1) {
				if (row>=L) {
					memo++;
					row=1;
				}
				else {
					flag=false;
					break;
				}
			}
			else if (memo==A[j][i]+1) {
				int sta=j+1, tro=1;
				while (sta<N && A[j][i]==A[sta][i] && tro<L) {
					sta++;
					tro++;
				}
				if (tro>=L) {
					j+=L-1;
					row=0;
					memo--;
				}
				else {
					flag=false;
					break;
				}
			}
			else {
				flag=false;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}	
	cout << ans;

	return 0;
}
