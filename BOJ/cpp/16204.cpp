#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	cout << min(m, k)+min(n-m, n-k);

	return 0;
}
