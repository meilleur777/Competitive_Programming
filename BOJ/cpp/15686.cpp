#include <stdio.h>
#include <math.h>
#include <vector>
#define INF 0x3F3F3F3F
using namespace std;

int result = INF;
typedef pair<int, int> p;
int N, M;
vector<p> chicken;
int chickennum = 0;
int map[51][51];

void solve(int last, int m) {
	for (int k = last + 1; k < chickennum; k++) {
		map[chicken[k].first][chicken[k].second] = 2;
		solve(k, m + 1);
		map[chicken[k].first][chicken[k].second] = 0;
	}
	
	if (m == M) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					int min = INF;
					for (int l = 0; l < N; l++) {
						for (int o = 0; o < N; o++) {
							if (map[l][o] == 2) {
								int temp = abs(i - l) + abs(j - o);
								min = min < temp ? min : temp;
							}
						}
					}
					sum += min;
				}
			}
		}
		result = result < sum ? result : sum;
		return;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
				chickennum++;
				map[i][j] = 0;
			}
		}
	}
	solve(-1, 0);
	printf("%d\n", result);
}

