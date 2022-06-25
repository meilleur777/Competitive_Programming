#include <iostream>
#define NUM 1000000007
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cache[101], C; cin >> C;
	cache[1] = 1, cache[2] = 2;
	for (int i = 3; i <= 100; i++)
		cache[i] = ((cache[i - 1] % NUM) + (cache[i - 2] % NUM)) % NUM;
	while (C--) {
		int n; cin >> n;
		cout << cache[n] << '\n';		
	}	
}

