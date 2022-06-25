#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	int now=1;
	while (true) {
		cout << now;
		if (now%m==0) cout << '\n';
		else cout << ' ';
		now++;
		if (now==n*m+1) return 0;
	}

	return 0;
}
