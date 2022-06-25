#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

bool chk(double N, int M, double P, double C) {
	while (M--) {
		N *= (1.0+(P/12.0)/100.0);
		N -= C;
	}
	return N <= 0;
}

double solve(double N, int M, double P) {
	int cnt = 100;
	double left = 0, right = N*(1.0+(P/12.0)/100.0);
	while (cnt--) {
		double mid = (left+right)/2.0;
		if (chk(N, M, P, mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	return right;
}

int main() {
	fast_io;
	
	cout << fixed;
	cout.precision(10);

	int T;
	cin >> T;
	while (T--) {
		double N, M, P;
		cin >> N >> M >> P;
		double res = solve(N, M, P);
		cout << res << '\n';
	}

	return 0;
}
