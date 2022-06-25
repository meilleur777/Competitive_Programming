#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, -1, 1 };

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int count = 0;
		char map[110][110];
		bool key[30] = { false }, vis[110][110] = { false };
		queue<pair<int, int> > q;
		int h, w; scanf("%d %d", &h, &w);
		memset(map, '.', sizeof(map));
		for (int j = 1; j <= h; j++) scanf(" %s", map[j] + 1);
		
		char keys[30]; scanf("%s", keys);
		if (keys[0] != '0') {
			int len = strlen(keys);
			for (int j = 0; j < len; j++) key[keys[j] - 'a'] = true;
		}
		
		for (int j = 1; j <= h; j++) { q.push(make_pair(j, 0)); q.push(make_pair(j, w + 1)); }
		for (int j = 1; j <= w; j++) { q.push(make_pair(0, j)); q.push(make_pair(h + 1, j)); }
		
		while (!q.empty()) {
			int row = q.front().first, col = q.front().second; q.pop();
			for (int k = 0; k < 4; k++) {
				int trow = row + rdi[k], tcol = col + cdi[k];
				if (trow >= 1 && trow <= h && tcol >= 1 && tcol <= w && !vis[trow][tcol]) {
					if (map[trow][tcol] == '.') {
						vis[trow][tcol] = true;
						q.push(make_pair(trow, tcol));
					}
					else if (map[trow][tcol] >= 'A' && map[trow][tcol] <= 'Z' 
							&& key[map[trow][tcol] -'A']) {
						vis[trow][tcol] = true;
						map[trow][tcol] = '.';
						q.push(make_pair(trow, tcol));
					}
					else if (map[trow][tcol] >= 'a' && map[trow][tcol] <= 'z') {
						if (!key[map[trow][tcol] - 'a']) {
							memset(vis, false, sizeof(vis));
							vis[trow][tcol] = true;
							key[map[trow][tcol] - 'a'] = true;
							map[trow][tcol] = '.';
							
							while (!q.empty()) q.pop();
							q.push(make_pair(trow, tcol));
							for (int j = 1; j <= h; j++) {
								q.push(make_pair(j, 0));
								q.push(make_pair(j, w + 1));
							}
							for (int j = 1; j <= w; j++) {
								q.push(make_pair(0, j));
								q.push(make_pair(h + 1, j));
							}
							break;
						}
						else {
							vis[trow][tcol] = true;
							map[trow][tcol] = '.';
							q.push(make_pair(trow, tcol));
						}
					}
					else if (map[trow][tcol] == '$') {
						count++;
						vis[trow][tcol] = true;
						map[trow][tcol] = '.';
						q.push(make_pair(trow, tcol));
					}
				} 
			}
		}
 		printf("%d\n", count);
	}
}

