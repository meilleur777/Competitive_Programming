#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int arr[9][9], temp[9][9], N, M;
int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

void DFS(pair<int, int> l) {
	int row = l.first;
	int col = l.second;
	temp[row][col] = 2;
	
	for (int i = 0; i < 4; i++) {
		int trow = row + rdi[i], tcol = col + cdi[i];
		if (trow >= 0 && trow < N && tcol >= 0 && tcol < M 
		&& !arr[trow][tcol] && temp[trow][tcol] != 2) 
			DFS(make_pair(trow, tcol));
	}
}

int count0() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!arr[i][j] && temp[i][j] != 2) count++;
		}
	}
	return count;
}

int main() {
	int res, max = -1;
	scanf("%d %d", &N, &M);
	vector<pair<int, int> > v;		/*빈 칸의 정보 저장 first = row, second = col*/
	vector<pair<int, int> > p;		/*바이러스 정보 저장*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (!arr[i][j]) v.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) p.push_back(make_pair(i, j));
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				memset(temp, 0, sizeof(int) * 9 * 9);
				arr[v[i].first][v[i].second] = 1;
				arr[v[j].first][v[j].second] = 1;
				arr[v[k].first][v[k].second] = 1;
				
				for (auto l : p) DFS(l);
				if ((res = count0()) > max) max = res;
								
				arr[v[i].first][v[i].second] = 0;
				arr[v[j].first][v[j].second] = 0;
				arr[v[k].first][v[k].second] = 0;
			}
		}
	}
	printf("%d\n", max);
}

