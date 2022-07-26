#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int q=a+b, p=a-b;
	if (q%2 || p%2 || p<0) cout << -1;
	else {
		q/=2, p/=2;
		cout << q << ' ' << p;
	}

	return 0;
}
