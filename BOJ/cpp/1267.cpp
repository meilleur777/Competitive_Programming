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

	int N;
	cin >> N;
	int y=0, m=0;
	rep(i, N) {
		int x;	
		cin >> x;
		y+=(x/30+1)*10;
		m+=(x/60+1)*15;
	}
	if (y>m) {
		cout << "M " << m;
	}
	else if (y==m) {
		cout << "Y M " << m;
	}
	else {
		cout << "Y " << y;
	}

	return 0;
}
