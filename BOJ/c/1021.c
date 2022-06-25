#include <stdio.h>
#include <stdbool.h>

/*어떤 원소 a(b)가 현재 a(1)의 위치로 이동하는데 드는 비용
1.왼쪽 = b가 1에 도착할 때까지 직접 옮겨본다.
2.오른쪽 = 전체 원소의 개수에서 왼쪽을 뺀다.

오른쪽으로 직접 옮겨보는 것이 더 쉬울듯하다. (양방향)

오답 이유 - 현재 큐의 가장 첫 원소 위치를 저장하는 pointer라는 변수를
원소를 뽑아내는 과정에서 단순히 1을 더하기만 했다.*/

int main() {
	int N, M, answer = 0, pointer = 1;
	bool arr[51] = { false };
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int order, count = 0; scanf("%d", &order);
		for (; pointer != order; pointer = pointer % N + 1) 
			if (!arr[pointer]) count++;
		answer += count < N - i - count ? count : N - i -count;
		pointer = pointer % N + 1;
		arr[order] = true;
	}
	printf("%d\n", answer);
}

