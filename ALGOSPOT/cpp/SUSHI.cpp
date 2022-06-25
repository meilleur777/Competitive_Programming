#include <iostream>
using namespace std;

int n, m, pref[21], price[21], cache[201];

int sushi() {
	int ret = 0; cache[0] = 0;
	for (int budget = 1; budget <= m; budget++) {
		int cand = 0;
		for (int dish = 0; dish < n; dish++) {
			if (budget >= price[dish]) {
				cand = max(cand, 
				cache[(budget - price[dish]) % 201] + pref[dish]);
			}
		}
		cache[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n >> m; m /= 100;
		for (int i = 0; i < n; i++) {
			int x; cin >> x >> pref[i];
			price[i] = x / 100;
		}
		cout << sushi() << '\n';	
	}
}

