#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N, K;
	cin >> N >> K;
	vector<string> A(N);
	rep(i, N) cin >> A[i];
	int now=0;
	for (auto i : A) {
		if (now+i.size()>K) {
			cout << '\n';
			cout << i;
			now=i.size();
		}
		else if (now==0) {
			now=i.size();
			cout << i;
		}
		else {
			now+=i.size();
			cout << ' ' << i;
		}
	}

	return 0;
}
