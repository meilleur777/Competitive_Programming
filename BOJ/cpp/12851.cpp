#include <stdio.h>
#include <queue>
#define MAX 100000 + 1
using namespace std;

int main() {
	int N, K; scanf("%d %d", &N, &K);
	int vis[MAX] = { 0 }, min = MAX, count = 0;
	int d = MAX % 2;
	printf("%d\n", d);
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int t = q.front().first;
		int c = q.front().second;
		vis[t] = 1;
		q.pop();
		if (t == K) {
			min = c;
			count++;
		}
		if (c > min) break;
		if (t > 0 && !vis[t - 1]) q.push(make_pair(t - 1, c + 1));
		if (t < MAX - 1 && !vis[t + 1]) q.push(make_pair(t + 1, c + 1));
		if (t <= 50000 && !vis[t * 2]) q.push(make_pair(t * 2, c + 1));
	}
	printf("%d\n%d", min, count);
}

