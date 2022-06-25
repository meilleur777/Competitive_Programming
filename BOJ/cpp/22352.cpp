#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> p;

int N, M;
bool visit[31][31] = { false };
int before[31][31], after[31][31];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

/*오답 이유 : 만일 입력이 before = { 2, 2 } after = { 2, 3 }이라고 할 때, 3을 주사하여 
before = { 3, 3 }이 될 것이다. 그러나 기존의 코드에서는 이미 지나온 칸을 다시 확인하지 않기
때문에 before[1]의 덩어리와 after[1]의 덩어리를 같은 것으로 보고 YES를 출력한다. 
지나온 칸까지 모두 확인하여 해결하였다.*/

/*다른 칸이 발견되면 그 칸의 좌표를, 아니면 { -1, -1 } 반환*/
p compare() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (before[i][j] != after[i][j]) return { i, j };
		}
	}
	return { -1, -1 }; 
} 

void DFS(int y, int x, int A, int B) {
	visit[y][x] = true; before[y][x] = B;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny > N || ny < 0 || nx > M || nx < 0 || visit[ny][nx]) continue;
		if (before[ny][nx] == A) DFS(ny, nx, A, B);		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> before[i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> after[i][j];
	
	int tx = compare().first, ty = compare().second;
	if (tx != -1) DFS(tx, ty, before[tx][ty], after[tx][ty]);
	if (compare().first != -1) cout << "NO\n";
	else cout << "YES\n";
}

