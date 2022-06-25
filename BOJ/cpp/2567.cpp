#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int res = 0;
bool board[110][110] = { false };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		for (int j = a + 1; j < a + 11; j++) {
			for (int k = b + 1; k < b + 11; k++) {
				board[j][k] = true;
			}
		}
	}
		
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			if (board[i][j] != board[i][j + 1]) {
				res++;
			}
			if (board[j][i] != board[j + 1][i]) {
				res++;
			}
		}
	}
	
	cout << res;
}

