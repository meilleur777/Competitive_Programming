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

	int N;
	cin >> N;
	vector<int> v, A(N);
	v.push_back(-1);
	rep(i, N) cin >> A[i];
	rep(i, N) {
		if (v.back()<A[i]) v.push_back(A[i]);
		else *lower_bound(v.begin(), v.end(), A[i])=A[i];
	}
	cout << v.size()-1;

	return 0;
}
