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
	int row=0;
	int ans=0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		if (a==b) row++;
		else row=0;
		ans=max(ans, row);
	}
	if (ans>=3) cout << "Yes";
	else cout << "No";

	return 0;
}
