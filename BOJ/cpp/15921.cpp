#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout << fixed;
	cout.precision(2);
	
	int n;
	cin >> n;
	vector<ld> a(n);
	rep(i, n) cin >> a[i];

	if (!n) {
		cout << "divide by zero";
	}
	else {
		cout << "1.00";
	}

	return 0;
}
