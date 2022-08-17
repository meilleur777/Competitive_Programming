#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout << "Gnomes:\n";
	
	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a<b && b<c) || (a>b && b>c)) cout << "Ordered\n";
		else cout << "Unordered\n";
	}

	return 0;
}
