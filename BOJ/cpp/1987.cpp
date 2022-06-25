#include <iostream>
using namespace std;

/*Brute-Force*/

/*최대 경우 4^26이라 생각했지만, 실제로 그리 많지 않은 듯하다.
선택되지 않은 알파벳만을 따라가므로, 하나의 경우에 대해 거의 상수 시간인가?*/

int R, C;
char board[22][22];
bool check[27] = { false };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

/*앞으로 더 나아갈 수 있는 최대 칸 수 반환, 현재 칸 포함*/
int DFS(int y, int x) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny > R || ny < 1 || nx > C || nx < 1 || check[board[ny][nx] - 'A']) continue;
		check[board[ny][nx] - 'A'] = true;
		ret = max(ret, DFS(ny, nx) + 1);
		check[board[ny][nx] - 'A'] = false;
	}	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	cin >> R >> C;
	string temp;
	for (int i = 1; i <= R; i++) {
		cin >> temp;
		for (int j = 1; j <= C; j++) board[i][j] = temp[j - 1];
	}
	check[board[1][1] - 'A'] = true; 
	cout << DFS(1, 1) << '\n';
}

