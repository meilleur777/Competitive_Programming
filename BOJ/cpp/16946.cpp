#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

/*미리 배열에 DFS를 사용해 0의 집단을 나누어 놓는다.
벽을 발견하면 상하좌우로 집단들의 파워를 더한다. 이때 겹치는 집단을 중복해서 더하지 않도록
set을 사용한다. 여기에 1-벽 자신의 크기-를 더하면 정답이다.*/

int num = 0;
int count, N, M;
int map[1001][1001];
int vis[1001][1001];	/*DFS에 이용*/
int team[1001][1001];	/*속한 그룹 번호 0부터 시작 -> 벡터 인덱싱*/
vector<int> power;	/*그룹의 파워*/
int res[1001][1001] = { 0 }; 

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

void DFS(int row, int col) {
	vis[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int trow = row + rdi[i];
		int tcol = col + cdi[i];
		if (trow >= 0 && trow < N && tcol >= 0 && tcol < M 
		&& !vis[trow][tcol] && !map[trow][tcol]) {
			team[trow][tcol] = num;
			count++;
			DFS(trow, tcol);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && !vis[i][j]) {
				count = 1;
				team[i][j] = num;
				DFS(i, j);
				power.push_back(count);
                num++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++) {
					int trow = i + rdi[k];
					int tcol = j + cdi[k];
					if (trow >= 0 && trow < N && tcol >= 0 && tcol < M && !map[trow][tcol]) 
						s.insert(team[trow][tcol]);
				}
				for (auto l : s) res[i][j] += power[l];
				res[i][j]++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", res[i][j] % 10);
		}
		printf("\n");
	}
}

