#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

bool board[101][101] = { false };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				board[j][k] = true;
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			res += board[i][j];
		}
	}
	cout << res;
}

