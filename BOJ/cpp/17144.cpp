#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int cleanerNum = 0;
pair<int, int> cleaner[2];
int R, C, T, map[51][51];

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

void upperCleaner() {
	pair<int, int> now = cleaner[0];
	now.second++;
	int temp1 = 0, temp2;
	while (now.second < C - 1) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.second++;
	}
	while (now.first > 0) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.first--;
	}
	while (now.second > cleaner[0].second) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.second--;
	}
	while (now.first < cleaner[0].first) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.first++;
	}
}

void lowerCleaner() {
	pair<int, int> now = cleaner[1];
	now.second++;
	int temp1 = 0, temp2;
	while (now.second < C - 1) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.second++;
	}
	while (now.first < R - 1) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.first++;
	}
	while (now.second > 0) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.second--;
	}
	while (now.first > cleaner[1].first) {
		temp2 = map[now.first][now.second];
		map[now.first][now.second] = temp1;
		temp1 = temp2;
		now.first--;
	}
}

int main() {
	scanf("%d %d %d", &R, &C, &T);
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				cleaner[cleanerNum].first = i;
				cleaner[cleanerNum++].second = j;					
			}
		}
	}
	
	while (T--) {
		int nmap[51][51] = { 0 };
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] > 0) {
					int dust = map[i][j] / 5, count = 0;
					for (int k = 0; k < 4; k++) {
						int trow = i + rdi[k];
						int tcol = j + cdi[k];
						if (trow >= 0 && trow < R && tcol >= 0 && tcol < C
						&& map[trow][tcol] != -1) {
							count++;
							nmap[trow][tcol] += dust;
						}
					}
					map[i][j] -= count * dust;
				}
			}
		}
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += nmap[i][j];
			}
		}
		
		upperCleaner();
		lowerCleaner();
	}
	
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sum += map[i][j];
		}
	}
	printf("%d\n", sum + 2);
}

