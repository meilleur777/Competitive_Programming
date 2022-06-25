#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char board[11][11];

typedef pair<int, int> p;

int best = 111;

/*왼쪽 0, 오른쪽 1, 위쪽 2, 아래쪽 3*/
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void solve(int dir, int count, p Rloc, p Bloc) {
	if (count >= 11) return;
	
	p memoRloc = Rloc;
	p memoBloc = Bloc;
	
	/*파란 공 움직이기*/
	bool Bflag = false;
	while (true) {
		if (board[Bloc.first][Bloc.second] == '#') {
			Bloc.first -= dy[dir];
			Bloc.second -= dx[dir];
			break;
		}
		else if (board[Bloc.first][Bloc.second] == 'O')	{
			Bflag = true;
			break;
		}
		
		Bloc.first += dy[dir];
		Bloc.second += dx[dir];
	}
	if (Bflag) return;
	
	/*빨간 공 움직이기*/
	bool Rflag = false;
	while (true) {
		Rloc.first += dy[dir];
		Rloc.second += dx[dir];
		
		if (board[Rloc.first][Rloc.second] == '#') {
			Rloc.first -= dy[dir];
			Rloc.second -= dx[dir];
			break;
		}
		else if (board[Rloc.first][Rloc.second] == 'O')	{
			Rflag = true;
			break;
		}
	}
	
	/*겹치는지 확인하기*/ 
	/*겹친다는 것은 같은 줄에 있었다는 것이기 때문에 이동 거리가 긴 쪽을
	한 칸 당겨주면 된다.*/
	if (Rloc == Bloc) {
		if (abs(memoRloc.first - Rloc.first) + abs(memoRloc.second - Rloc.second) >
		abs(memoBloc.first - Bloc.first) + abs(memoBloc.second - Bloc.second))	{
			Rloc.first -= dy[dir];
			Rloc.second -= dx[dir];
		}	
		else {
			Bloc.first -= dy[dir];
			Bloc.second -= dx[dir];
		}		
	}
	
	/*성공했는지 확인하기*/
	if (Rflag && !Bflag) {
		best = min(best, count);
		return;
	}
	
	/*다음 시행 호출하기*/
	int forbid;
	switch (dir) {
		case 0: forbid = 1; break;
		case 1: forbid = 0; break;
		case 2: forbid = 3; break;
		case 3: forbid = 2; break;
	}
	for (int i = 0; i < 4; i++) {
		if (i == forbid) continue;
		
		solve(i, count + 1, Rloc, Bloc);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	cin >> N >> M;
	
	p Rloc, Bloc;
	
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'R') {
				Rloc = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				Bloc = { i, j };
				board[i][j] = '.';
			}
		}
	}	
	
	for (int i = 0; i < 4; i++) {
		solve(i, 1, Rloc, Bloc);
	}	
	
	if (best == 111) cout << "-1\n";
	else cout << best << '\n';
}

