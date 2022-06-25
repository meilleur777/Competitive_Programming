#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int depth;
} fishes;

fishes queue[10000];
int fishfront = 0, fishback = 0;
int arr[21][21], N;
int size = 2, cnt = 0, time = 0;
int rowdir[4] = { -1, 0, 0, 1 };
int coldir[4] = { 0, -1, 1, 0 };
int nrow, ncol;

int cpr(const void *a, const void *b) {
	fishes *m = (fishes *)a, *n = (fishes *)b;
	return (m->depth > n->depth) ? 1 : (m->depth < n->depth) ? -1 :
		   (m->row > n->row) ? 1 : (m->row < n->row) ? -1 :
		   (m->col > n->col) ? 1 : (m->col < n->col) ? -1 : 0; 	
}


/*srow, scol로부터 접근 가능한 물고기의 목록 생성*/ 
void BFS(int srow, int scol) {
	int vis[21][21] = { 0 };
	int rowque[10000], colque[10000];
	int front = 0, back = 0;

	vis[srow][scol] = 1;
	rowque[back] = srow;
	colque[back++] = scol;

	while (front < back) {
		int trow = rowque[front];
		int tcol = colque[front++];
		
		if (arr[trow][tcol] > 0 && arr[trow][tcol] < size) {
			queue[fishback].row = trow;
			queue[fishback].col = tcol;
			queue[fishback++].depth = vis[trow][tcol] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int mrow = trow + rowdir[i], mcol = tcol + coldir[i];
			if (mrow >= 0 && mrow < N && mcol >= 0 && mcol < N &&
				!vis[mrow][mcol] && arr[mrow][mcol] <= size) {
				rowque[back] = mrow;
				colque[back++] = mcol;
				vis[mrow][mcol] = vis[trow][tcol] + 1;
			}
		}
	}
}

int main() {
	int srow, scol; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				srow = i;
				scol = j;
				arr[i][j] = 0;
			}
		}
	}
	BFS(srow, scol);
	while (0 < fishback) {
		qsort(queue, fishback, sizeof(fishes), cpr);
		time += queue[0].depth;
		srow = queue[0].row;
		scol = queue[0].col;
		fishback = 0;
		arr[srow][scol] = 0;
		cnt++;
		if (cnt == size) {
			cnt = 0;
			size++;
		}
		BFS(srow, scol);
	}
	printf("%d\n", time);
}

