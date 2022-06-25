#include <iostream>
#include <string.h>
#include <algorithm>
#define NEGINF -987654321
using namespace std;

/*로봇이 왼쪽으로도 이동할 수 있기 때문에 단순히 2차원 배열로 cache를 저장할 수 없다.
예를 들어 왼쪽으로 갔다가 아래로 한 칸 갔다가 다시 오른쪽으로 돌아오는 것이 바로 한 칸 내려가는
것보다 얻는 가치가 클 수 있다. 그러나 cache를 2차원으로 저장하면 그러한 경우를 고려할 수 없다.*/

int dy[3] = { 0, 1, 0 };
int dx[3] = { -1, 0, 1 };

int N, M;
bool visit[1002][1002] = { false };
int map[1002][1002], cache[1002][1002][3];

bool inRange(int y, int x) { return (y > 0 && y <= N && x > 0 && x <= M); }

/*(y, x)에서 (N, M)으로 가는 데 얻을 수 있는 최대 가치 반환*/
int solve(int y, int x, int dir) {
	if (y == N && x == M) return map[y][x];
	
	int& ret = cache[y][x][dir];
	if (ret != NEGINF) return ret;
	
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!inRange(ny, nx)) continue;
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			ret = max(ret, solve(ny, nx, i) + map[y][x]);
			visit[ny][nx] = false;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&cache[0][0][0], &cache[0][0][0] + 1002 * 1002 * 3 + 1, NEGINF);	
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	visit[1][1] = true;
	cout << solve(1, 1, 0) << '\n';	
}

