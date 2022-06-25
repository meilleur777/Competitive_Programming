#include <stdio.h>
#include <iostream>
using namespace std;

int N, cache[10001][11], before[10001], after[10001], choice[10001][11]; 

int solve(int current, int turn) {
	if (current == N) return 0;
	
	int& ret = cache[current][turn];
	int& choose = choice[current][turn];
	if (ret != -1) return ret;
	
	int turned = (before[current] + turn) % 10; 
	int toLeft = after[current] - turned;
	if (after[current] < turned) toLeft += 10;
	int toRight = 10 - toLeft;
	
	int ifLeft = toLeft + solve(current + 1, (turn + toLeft) % 10);
	int ifRight = toRight + solve(current + 1, turn);
	if (ifLeft < ifRight) {
		choose = (turn + toLeft) % 10;
		return ret = ifLeft;
	}
	else {
		choose = turn;
		return ret = ifRight;
	}
}

void reconstruct(int current, int turn) {
	if (current == N) return;
	int choose = choice[current][turn];
	
	int turned = (before[current] + turn) % 10; 
	int toLeft = after[current] - turned;
	if (after[current] < turned) toLeft += 10;
	int toRight = 10 - toLeft;
	
	cout << current + 1 << ' ';
	if (choose == (turn + toLeft) % 10) {
		cout << solve(current, turn) - 
		solve(current + 1, (turn + toLeft) % 10) <<'\n';
		reconstruct(current + 1, (turn + toLeft) % 10);
	}
	else {
		cout << solve(current + 1, turn) - solve(current, turn) << '\n';
		reconstruct(current + 1, turn);
	}
}

int main() {
	cin >> N;	
	fill_n(&cache[0][0], 10001 * 11, -1);
	for (int i = 0; i < N; i++) scanf("%1d", &before[i]);
	for (int i = 0; i < N; i++) scanf("%1d", &after[i]);
	cout << solve(0, 0) << '\n';
	reconstruct(0, 0);
}

