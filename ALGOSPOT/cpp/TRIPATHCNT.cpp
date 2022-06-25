#include <iostream>
#include <string.h>
using namespace std;

int n, tri[101][101];
int pathCache[101][101], countCache[101][101];

int path(int y, int x) {
	if (y == n - 1) return tri[y][x];
	int& ret = pathCache[y][x];
	if (ret != -1) return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}

int count(int y, int x) {
	if (y == n - 1) return 1;
	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	if (path(y + 1, x + 1) >= path(y + 1, x)) ret += count(y + 1, x + 1);
	if (path(y + 1, x + 1) <= path(y + 1, x)) ret += count(y + 1, x);
	return ret;	 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n;
		memset(pathCache, -1, sizeof(pathCache));
		memset(countCache, -1, sizeof(countCache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		cout << count(0, 0) << '\n';
	}
}

