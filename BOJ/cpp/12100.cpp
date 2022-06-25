#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int N, max = 0;
int board[21][21];

void left() {
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				board[i][temp] = board[i][j];
				if (temp++ != j) board[i][j] = 0;
			}
		}
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				board[i][j] *= 2;
				for (int k = j + 1; k < N - 1; k++) board[i][k] = board[i][k + 1];
				board[i][N - 1] = 0;
			}
		}
	}
}

void right() {
	for (int i = 0; i < N; i++) {
		int temp = N - 1;
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j] != 0) {
				board[i][temp] = board[i][j];
				if (temp-- != j) board[i][j] = 0;
			}
		}
		for (int j = N - 1; j > 0; j--) {
			if (board[i][j] == board[i][j - 1]) {
				board[i][j] *= 2;
				for (int k = j - 1; k > 0; k--) board[i][k] = board[i][k - 1];
				board[i][0] = 0;
			}
		}
	}
}

void up() {
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (board[j][i] != 0) {
				board[temp][i] = board[j][i];
				if (temp++ != j) board[j][i] = 0;
			}
		}
		for (int j = 0; j < N - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				board[j][i] *= 2;
				for (int k = j + 1; k < N - 1; k++) board[k][i] = board[k + 1][i];
				board[N - 1][i] = 0;
			}
		}
	}
}

void down() {
	for (int i = 0; i < N; i++) {
		int temp = N - 1;
		for (int j = N - 1; j >= 0; j--) {
			if (board[j][i] != 0) {
				board[temp][i] = board[j][i];
				if (temp != j) board[j][i] = 0;
				temp--;
			}
		}
		for (int j = N - 1; j > 0; j--) {
			if (board[j][i] == board[j - 1][i]) {
				board[j][i] *= 2;
				for (int k = j - 1; k > 0; k--) board[k][i] = board[k - 1][i];
				board[0][i] = 0;
			}
		}
	}
}

void solve(int count, int nextMove) {
	int copy[21][21];
	switch(nextMove) {
		case 0: left(); break;
		case 1: up(); break;
		case 2: right(); break;
		case 3: down(); break;
	}
	if (count == 4) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) max = MAX(max, board[i][j]);
		return;
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) copy[i][j] = board[i][j];
	for (int i = 0; i < 4; i++) {
		solve(count + 1, i);
		for (int k = 0; k < N; k++) for (int j = 0; j < N; j++) board[k][j] = copy[k][j];
	}
}

int main() {
	int copy[21][21]; 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
			copy[i][j] = board[i][j]; 
			max = MAX(max, board[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		solve(0, i);
		for (int k = 0; k < N; k++) for (int j = 0; j < N; j++) board[k][j] = copy[k][j];
	}
	printf("%d\n", max);
}

