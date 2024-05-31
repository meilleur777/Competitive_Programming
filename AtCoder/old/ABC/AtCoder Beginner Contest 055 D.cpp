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
	string A;
	cin >> N >> A;
	vector<int> B(N);
	for (int i=0; i<A.size(); i++) {
		B[i]=(A[i]=='o')?false:true;
	}
	for (int f=0; f<2; f++) {
		for (int s=0; s<2; s++) {
			vector<int> can(N);
			can[0]=f;
			can[1]=s;
			for (int i=1; i<N-1; i++) {
				can[i+1]=((can[i]==B[i])==can[i-1]);
			}
			bool flag=true;
			if (can[0]!=((can[N-1]==B[N-1])==can[N-2])) flag=false;
			if (can[1]!=((can[0]==B[0])==can[N-1])) flag=false;
			if (flag) {
				for (auto i : can) {
					if (i==0) cout << 'S';
					else cout << 'W';
				}
				return 0;
			}
		}
	}
	cout << -1;

	return 0;
}
