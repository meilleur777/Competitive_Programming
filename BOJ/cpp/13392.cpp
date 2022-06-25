#include <stdio.h>
#include <iostream>
using namespace std;

/*각각의 숫자나사에 대하여 선택 가능한 경우는 왼쪽 또는 오른쪽의 2가지이다.
이때 아직 돌리기 전의 어떤 숫자나사의 현재 상태는 위쪽 숫자나사들을 왼쪽으로
돌린 횟수에 따라 결정되므로, 현재 돌리는 숫자나사의 번호, 위에서 왼쪽으로 돌린
횟수를 기억한다. 이때, 돌린 횟수 % 10만을 기억하면 된다. */

int N, cache[10001][11], before[10001], after[10001];

int solve(int current, int turn) {
	if (current == N) return 0;
	
	int& ret = cache[current][turn];
	if (ret != -1) return ret;
	
	int turned = (before[current] + turn) % 10; 
	int toLeft = after[current] - turned;
	if (after[current] < turned) toLeft += 10;
	int toRight = 10 - toLeft;
	
	return ret = min(toLeft + solve(current + 1, (turn + toLeft) % 10), 
	toRight + solve(current + 1, turn));	
}

int main() {
	cin >> N;	
	fill_n(&cache[0][0], 10001 * 11, -1);
	for (int i = 0; i < N; i++) scanf("%1d", &before[i]);
	for (int i = 0; i < N; i++) scanf("%1d", &after[i]);
	cout << solve(0, 0) << '\n';
}

