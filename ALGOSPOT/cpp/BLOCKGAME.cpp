#include <vector>
#include <iostream>
using namespace std;

inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;
char cache[1 << 25];

/*보드에 블록을 놓는 모든 경우를 int형으로 계산한다.*/
void precalc() {
	/*세 칸짜리*/
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int sum = 0, cells[4];
			for (int dy = 0; dy < 2; dy++) {
				for (int dx = 0; dx < 2; dx++) {
					cells[dy * 2 + dx] = cell(y + dy, x + dx);
					sum += cells[dy * 2 + dx];
				}
			}
			for (int i = 0; i < 4; i++) moves.push_back(sum - cells[i]);
		}
	}
	
	/*두 칸짜리*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

/*현재 보드 상태가 current일 때, 현재 차례인 사람이 승리하면 1, 아니면 0 반환*/
char solve(int current) {
	char& ret = cache[current];
	if (ret != -1) return ret;
	
	ret = 0;
	/*가능한 모든 수 중에서*/
	for (int i = 0; i < moves.size(); i++) {
		/*이 수를 놓을 수 있고, 이 수를 놓았을 때 다음 사람이 패배한다면*/
		if (!(moves[i] & current) && !solve(current | moves[i])) {
			ret = 1;
			break;
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	precalc();
	
	int C; cin >> C;
	while (C--) {
		int base = 0;
		fill_n(cache, 1 << 25, -1);
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char x; cin >> x;
				if (x == '#') base |= cell(i, j);
			}	
		}
		if (solve(base)) cout << "WINNING\n";
		else cout << "LOSING\n";
	}	
}

