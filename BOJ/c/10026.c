#include <stdio.h>

int N;
int rowdir[4] = { 1, -1, 0, 0 };
int coldir[4] = { 0, 0, 1, -1 };
char apaint[101][101], bpaint[101][101];;
int avisit[101][101] = { 0 };
int bvisit[101][101] = { 0 };

void aDFS(int row, int col) {
	int k;
	avisit[row][col] = 1;
	for (k = 0; k < 4; k++) {
		int trow = row + rowdir[k];
		int tcol = col + coldir[k];
		if (trow >= 0 && trow < N && tcol >= 0 && tcol < N &&
			!avisit[trow][tcol] && apaint[row][col] == apaint[trow][tcol])
			aDFS(trow, tcol);
	}
}

void bDFS(int row, int col) {
	int k;
	bvisit[row][col] = 1;
	for (k = 0; k < 4; k++) {
		int trow = row + rowdir[k];
		int tcol = col + coldir[k];
		if (trow >= 0 && trow < N && tcol >= 0 && tcol < N &&
			!bvisit[trow][tcol] && bpaint[row][col] == bpaint[trow][tcol])
			bDFS(trow, tcol);
	}
}

int main() {
	int i, j; scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			char c; scanf(" %c", &c);
			apaint[i][j] = c;
			if (c == 'G') bpaint[i][j] = 'R';
			else bpaint[i][j] = c;
		}
	}

	int acnt = 0, bcnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!avisit[i][j]) { aDFS(i, j); acnt++; }
			if (!bvisit[i][j]) { bDFS(i, j); bcnt++; }
		}
	}
	printf("%d %d\n", acnt, bcnt);
}
