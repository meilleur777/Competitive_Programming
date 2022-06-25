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

	int n;
	cin >> n;
	vector<int> a(n+1, 0);
	for (int i=2; i<=n; i++) {
		int num=1;
		for (int j=i; j<=n; j+=i) {
			if (a[j])
			a[j]=num;
		}
	}
	for (int i=1; i<=n; i++) {
		cout << a[i]
	}

	return 0;
}
