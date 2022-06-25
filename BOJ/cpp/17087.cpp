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

int gcd(int a, int b) {
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	init_code();

	int N, S;
	cin >> N >> S;
	int g;
	cin >> g;
	g=abs(g-S);
	rep(i, N-1) {
		int A;
		cin >> A;
		g=gcd(g, abs(A-S));
	}
	cout << g;

	return 0;
}
