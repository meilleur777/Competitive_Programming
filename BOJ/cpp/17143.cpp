#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int speed;
	int dir;
	int power;
} shark;

vector<shark> nshark[102][102], sharks[102][102];

bool compare(shark a, shark b) {
	return a.power > b.power;
}

int smove(int start, int bound, int count, int direc) {
	while (count--) {
		if (start + direc > bound || start + direc < 1) {
			direc *= -1;
		}
		else {
			start += direc;			
		}
	}
}

int main() {
	int R, C, M; scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z; scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		sharks[r][c].push_back({ s, d, z });
	}
	
	
	int score = 0;
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (!sharks[j][i].empty()) {
				score += sharks[j][i].front().power;
				sharks[j][i].clear();
				break;
			}
		}
		
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				if (!sharks[j][k].empty()) {
					int x, row, col, direc;
					shark temp = sharks[j][k].front();
					sharks[j][k].clear();
					
					switch (temp.dir) {
						case 1: 
							row = j, direc = -1;
							x = temp.speed % ((R - 1) * 2);
							while (x--) {
								if (row + direc > R || row + direc < 1) {
									direc *= -1;
									x++;
								}
								else row += direc;	
							}
							temp.dir = direc < 0 ? 1 : 2;							
							nshark[row][k].push_back(temp);
							break; 
						case 2: 	
							row = j, direc = 1;
							x = temp.speed % ((R - 1) * 2);
							while (x--) {
								if (row + direc > R || row + direc < 1) {
									direc *= -1;
									x++;
								}
								else row += direc;			
							}
							temp.dir = direc < 0 ? 1 : 2;
							nshark[row][k].push_back(temp);
							break;
						case 3: 
							col = k, direc = 1;
							x = temp.speed % ((C - 1) * 2);
							while (x--) {
								if (col + direc > C || col + direc < 1) {
									direc *= -1;
									x++;
								}
								else col += direc;			
							}
							temp.dir = direc > 0 ? 3 : 4;
							nshark[j][col].push_back(temp);
							break;
						case 4: 
							col = k, direc = -1;
							x = temp.speed % ((C - 1) * 2);
							while (x--) {
								if (col + direc > C || col + direc < 1) {
									direc *= -1;
									x++;
								}
								else col += direc;			
							}
							temp.dir = direc > 0 ? 3 : 4;
							nshark[j][col].push_back(temp);
					}
				}
			}
		}
		
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				while (!nshark[j][k].empty()) {
					sharks[j][k].push_back(nshark[j][k].back());
					nshark[j][k].pop_back();
				}
				
				if (sharks[j][k].size() > 1) {
					sort(sharks[j][k].begin(), sharks[j][k].end(), compare);
					shark temp = sharks[j][k].front();
					sharks[j][k].clear();
					sharks[j][k].push_back(temp);										
				}
			}
		}		
	}
	printf("%d\n", score);
}

