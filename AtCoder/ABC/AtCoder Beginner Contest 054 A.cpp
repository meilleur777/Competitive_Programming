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

	int A, B;
	cin >> A >> B;
	if (A==B) {
		cout << "Draw";
	}
	else if (A==13 && B==1) {
		cout << "Bob";
	}
	else if (A==1 && B==13) {
		cout << "Alice";
	}
	else if (A<B) cout << "Bob";
	else cout << "Alice";

	return 0;
}
