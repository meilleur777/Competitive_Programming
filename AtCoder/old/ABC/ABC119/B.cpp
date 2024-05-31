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

int main() {
	init_code();

	int N;
	cin >> N;
	ld sum=0.0, B=0.0;
	while (N--) {
		ld x;
		string u;
		cin >> x >> u;
		if (u=="JPY") {
			sum+=x;
		}
		else {
			B+=x;
		}
	}
	cout << sum+B*380000.0;

	return 0;
}
