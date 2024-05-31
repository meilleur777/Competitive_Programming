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

vector<int> a;
vector<int> cache;

/*win->1, lose->0*/
int solve(int rem) {
	int& ret=cache[rem];
	if (ret!=-1) return ret;
	for (int i=0; i<a.size(); i++) {
		if (rem-a[i]>=0 && solve(rem-a[i])==0) {
			return ret=1;
		}
	}
	return ret=0;
}

int main() {
	init_code();

	int N, K;
	cin >> N >> K;
	a.resize(N);
	cache=vector<int>(K+1, -1);
	rep(i, N) cin >> a[i];
	if (solve(K)==1) cout << "First";
	else cout << "Second";

	return 0;
}
