#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	vector<int> coin={25, 10, 5, 1};
	while (t--) {
		int a;
		cin >> a;
		for (int i=0; i<4; i++) {
			cout << a/coin[i] << ' ';
			a=a%coin[i];
		}
		cout << '\n';
	}

	return 0;
}
