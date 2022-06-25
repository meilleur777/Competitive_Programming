#include <iostream>
#include <string.h>
#define MOD 1000000007
using namespace std;

int n, cache[101] = { 1, 1, 2 };

int asymmetric(int width) {
	if (width % 2 == 1) return (cache[width] - cache[width / 2] + MOD) % MOD;
	int ret = cache[width];
	ret = (ret - cache[width / 2] + MOD) % MOD;
	ret = (ret - cache[width / 2 - 1] + MOD) % MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 3; i <= 101; i++)
		cache[i] = ((cache[i - 1] % MOD) + (cache[i - 2] % MOD)) % MOD;
			
	int C; cin >> C;
	while (C--) {
		cin >> n;
		cout << asymmetric(n) << '\n';
	}	
}

