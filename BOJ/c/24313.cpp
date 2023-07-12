#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	if (c<a1) cout << 0;
	else cout << (a1*n0+a0<=c*n0);

	return 0;
}
