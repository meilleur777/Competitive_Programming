#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, w, h;
	cin >> n >> w >> h;
	while (n--) {
		int a;
		cin >> a;
		if (w*w+h*h>=a*a) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}
