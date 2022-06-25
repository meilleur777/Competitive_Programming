#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
bool visit[32001] = { false };
vector<int> v[32001]; /*v[k] 학생 k보다 앞에 서야하는 학생*/

void BFS(int s) {
	visit[s] = true;
	for (auto i : v[s]) if (!visit[i]) BFS(i);
	printf("%d ", s);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B; scanf("%d %d", &A, &B);
		v[B].push_back(A); 
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		for (auto j : v[i]) if (!visit[j]) BFS(j);
		printf("%d ", i);
	}
}

