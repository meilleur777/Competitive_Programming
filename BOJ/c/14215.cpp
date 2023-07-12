#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	int t=max({a, b, c});
	if (t>=a+b+c-t) {
		cout << 2*(a+b+c-t)-1;
	}
	else {
		cout << a+b+c;
	}

	return 0;
}
