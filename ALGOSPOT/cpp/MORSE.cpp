#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int NUM = 1000000000 + 100;

int bino[201][201] = { 0 };

string solve(int n, int m, int skip) {
	if (!n) return string(m, 'o');
	if (skip < bino[n + m - 1][n - 1]) return '-' + solve(n - 1, m, skip);
	return 'o' + solve(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

void calbino() {
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) 
			bino[i][j] = min(NUM, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	calbino();
	int C; cin >> C;
	while (C--) {
		int n, m, k; cin >> n >> m >> k;
		cout << solve(n, m, k - 1) << '\n';
	}	
}
