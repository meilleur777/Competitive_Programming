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
	vector<int> P(M+1), Y(M+1);
	vector<vector<int> > A(N+1);
	rep(i, M) {
		cin >> P[i+1] >> Y[i+1];
		A[P[i+1]].push_back(Y[i+1]);
	}
	for (int i=1; i<=N; i++) {
		sort(A[i].begin(), A[i].end());
	}
	for (int i=1; i<=M; i++) {
		string t=to_string(P[i]);
		for (int j=0; j<6-(int)t.size(); j++) {
			cout << '0';
		}
		cout << t;
		int tmp=find(A[P[i]].begin(), A[P[i]].end(), Y[i])-A[P[i]].begin()+1;
		t=to_string(tmp);
		for (int j=0; j<6-(int)t.size(); j++) {
			cout << '0';
		}
		cout << t << '\n';
	}

	return 0;
}
