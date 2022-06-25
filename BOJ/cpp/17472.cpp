#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int s, u, w;
} edge;

vector<edge> edges;
int N, M, num = 1;
int map[11][11], island[11][11], parent[7];
bool visit[11][11] = { false };

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

bool compare(edge a, edge b) { return a.w < b.w; }

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a > b) parent[b] = a;
	else parent[a] = b;
}

void DFS(int row, int col) {
	island[row][col] = num;
	visit[row][col] = true;
	for (int i = 0; i < 4; i++) {
		int trow = row + rdi[i], tcol = col + cdi[i];
		if (trow >= N || trow < 0 || tcol >= M || tcol < 0 || visit[trow][tcol]) continue;
		if (map[trow][tcol]) DFS(trow, tcol);
	}
}

bool rowcheck(int col, int start, int end) {
	if (start > end) { int t = end; end = start; start = t; }
	for (int i = start + 1; i < end; i++) if (map[i][col]) return false;
	return true;
}

bool colcheck(int row, int start, int end) {
	if (start > end) { int t = end; end = start; start = t; }
	for (int i = start + 1; i < end; i++) if (map[row][i]) return false;
	return true;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visit[i][j]) {
				DFS(i, j);
				parent[num] = num;
				num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					if (!map[i][j] || !map[k][l] || island[i][j] == island[k][l]) continue;
					if (i == k && colcheck(i, j, l))
						edges.push_back({ island[i][j], island[k][l], abs(j - l) - 1 });
					else if (j == l && rowcheck(j, i, k))
						edges.push_back({ island[i][j], island[k][l], abs(i - k) - 1 });
				}
			}
		}
	}

	sort(edges.begin(), edges.end(), compare);

	int answer = 0;
	for (auto i : edges) {
		if (i.w == 1) continue;
		if (find(i.s) != find(i.u)) {
			merge(i.s, i.u);
			answer += i.w;
		}
	}

	bool flag = false;
	int temp = find(parent[1]);
	for (int i = 2; i < num; i++) {
		if (find(parent[i]) != temp) {
			flag = true;
			break;
		}
	}

	if (flag) printf("-1\n");
	else printf("%d\n", answer);
}

