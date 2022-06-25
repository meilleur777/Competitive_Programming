#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#define MOD 1000000007
using namespace std;

string e, digits;
int n, m, cache[1<<14][20][2];

int price(int index, int taken, int mod, int less) {
	if (index == n) return (less && !mod) ? 1 : 0;
	
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int next = 0; next < n; next++) {
		if (taken & (1 << next)) continue; 
		if (!less && e[index] < digits[next]) continue;
		if (next > 0 && digits[next - 1] == digits[next] && !(taken & (1 << (next - 1)))) 
			continue;
			
		ret += price(index + 1, taken | (1 << next),
		(mod * 10 + digits[next] - '0') % m, less || e[index] > digits[next]);
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C; cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache)); 
		cin >> e >> m;
		n = e.size();
		digits = e; sort(digits.begin(), digits.end());
		cout << price(0, 0, 0, 0) << '\n';
	}
}

