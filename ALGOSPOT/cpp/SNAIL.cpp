#include <iostream>
using namespace std;

int n, m;
double cache[3000][1001];

double solve(int climed, int days) {
	if (days == m) return (climed >= n) ? 1 : 0;
	double& ret = cache[climed][days];
	if (ret != -1) return ret;
	return ret = 0.25 * solve(climed + 1, days + 1) + 0.75 * solve(climed + 2, days + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << fixed;
	cout.precision(15);
		
	int C; cin >> C;
	while (C--) {
		fill(cache[0], cache[0] + 3000 * 1001 + 1, -1.0);
		cin >> n >> m;
		cout << solve(0, 0) << '\n';
	}
}

