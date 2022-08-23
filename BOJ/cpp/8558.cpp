#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int now=1;
	int n;
	cin >> n;
	rep(i, n) {
		now*=i+1;
		now%=10;
	}
	cout << now;

	return 0;
}
