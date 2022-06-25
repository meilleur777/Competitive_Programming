#include <iostream>
#include <algorithm>
#include <vector>
#define INF 9999
#define CLOCKS 16
#define SWITCHES 10
using namespace std;

const char linked[SWITCHES][CLOCKS + 1] = {
	"oooxxxxxxxxxxxxx",
	"xxxoxxxoxoxoxxxx",
	"xxxxoxxxxxoxxxoo",
	"oxxxooooxxxxxxxx",
	"xxxxxxoooxoxoxxx",
	"oxoxxxxxxxxxxxoo",
	"xxxoxxxxxxxxxxoo",
	"xxxxooxoxxxxxxoo",
	"xoooooxxxxxxxxxx",
	"xxxoooxxxoxxxoxx"
};

bool all12(vector<int>& state) {
	for (int i = 0; i < CLOCKS; i++) if (state[i] != 12) return false;
	return true;
}

void push(vector<int>& state, int button) {
	for (int i = 0; i < CLOCKS; i++) 
		if (linked[button][i] == 'o') 
			state[i] = (state[i] == 12) ? 3 : (state[i] + 3);
}

int solve(vector<int>& state, int count) {
	if (count == SWITCHES) return all12(state) ? 0 : INF;
	
	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, i + solve(state, count + 1));
		push(state, count);
	}
	return result;
}

int main() {
	int C; cin >> C;
	vector<int> state(CLOCKS);
	while (C--) {
		for (int i = 0; i < CLOCKS; i++) cin >> state[i];
		int result = solve(state, 0);
		if (result >= INF) cout << -1 << '\n';
		else cout << result << '\n';
	}	
}
