#include <iostream>
using namespace std;

const string name[5] = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int A[5][5], B[5][5], C[5][5] = { 0 }, D[5] = { 0 };	
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) cin >> A[i][j];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) cin >> B[i][j];
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			for (int i = 0; i < 5; i++) C[x][y] += A[x][i] * B[i][y];
			D[x] += C[x][y];
		}
	}
	int result, resultValue = INT_MAX;
	for (int i = 0; i < 5; i++) resultValue = min(resultValue, D[i]);
	for (int i = 4; i >= 0; i--) {
		if (resultValue == D[i]) {
			cout << name[i] << '\n';
			return 0;
		}
	}
}

