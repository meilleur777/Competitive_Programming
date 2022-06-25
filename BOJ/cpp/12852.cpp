#include <stdio.h>
#include <queue>
using namespace std;

int res[1000001];
int parent[1000001];
bool visit[1000001] = { false };
queue<int> q;

int main() {
	int num, N; scanf("%d", &N);
	parent[N] = -1, q.push(N);
	
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		
		if (temp == 1) break;
		
		num = temp / 3;
		if (!(temp % 3) && !visit[num]) {
			visit[num] = true;
			parent[num] = temp;
			q.push(num);
 		}
 		
 		num = temp / 2;
 		if (!(temp % 2) && !visit[num]) {
 			visit[num] = true;
			parent[num] = temp;
			q.push(num);
		}
		
		num = temp - 1;
		if (!visit[num]) {
			visit[num] = true;
			parent[num] = temp;
			q.push(num);
		}
	}
	
	int p = parent[1], cnt;	
	for (cnt = 0; p != -1; res[cnt++] = p, p = parent[p]);
	printf("%d\n", cnt);
	for (int i = cnt - 1; i >= 0; i--) printf("%d ", res[i]);
	printf("1");
}

