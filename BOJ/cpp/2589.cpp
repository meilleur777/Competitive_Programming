#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
char board[51][51];

int BFS(p S) {
	bool visit[51][51] = { false };
	queue<pair<p, int> > q;
	q.push({ S, 0 });
	visit[S.first][S.second] = true;
	
	int maxTime = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int time = q.front().second;
		q.pop();
		
		maxTime = max(maxTime, time);
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			
			if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
			if (visit[ny][nx]) continue;
			if (board[ny][nx] == 'W') continue;
			
			visit[ny][nx] = true;
			q.push({{ ny, nx }, time + 1 });
		}
	}
	
	return maxTime;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}	
	
	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'W') continue;
			ans = max(ans, BFS({ i, j }));
		}
	}
	cout << ans << '\n';
}

