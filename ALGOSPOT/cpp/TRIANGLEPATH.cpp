#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int tri[101][101];
int cache[101][101];

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		
		cache[0][0] = tri[0][0];
		for (int i = 1; i < n; i++) {
			cache[i][0] = cache[i - 1][0] + tri[i][0];
			for (int j = 1; j < i; j++)
				cache[i][j] = max(cache[i - 1][j - 1], cache[i - 1][j]) + tri[i][j];
			cache[i][i] = cache[i - 1][i - 1] + tri[i][i];
		}
		
		int result = -1;
		for (int i = 0; i < n; i++) result = max(result, cache[n - 1][i]);
		cout << result << '\n';
	}	
}

