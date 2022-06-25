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

	int a, b;
	cin >> a >> b;
	vector<int> v;
	v.push_back(0);
	for (int i=1; i<=50; i++) {
		for (int j=1; j<=i; j++) {
			v.push_back(i);
		}
	}
	ll sum=0;
	for (int i=a; i<=b; i++) {
		sum+=v[i];
	}
	cout << sum;

	return 0;
}
