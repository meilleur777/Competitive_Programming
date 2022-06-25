#include <math.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

string A;
int cache[10002];

int difficulty(int start, int end) {
	string temp = A.substr(start, end - start + 1);
	
	if (temp == string(temp.size(), temp[0])) return 1;
	
	bool progressive = true;
	for (int i = 0; i < temp.size() - 1; i++) {
		if (temp[i + 1] - temp[i] != temp[1] - temp[0]) {
			progressive = false;
			break;
		}
	}
	
	if (progressive && abs(temp[1] - temp[0]) == 1) return 2;
	
	bool alternating = true;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] != temp[i % 2]) {
			alternating = false;
			break;
		}
	}
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int solve(int a) {
	if (a == A.size()) return 0;
	
	int& ret = cache[a];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (a + L <= A.size()) 
			ret = min(ret, solve(a + L) + difficulty(a, a + L - 1));
	}
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> A;
		memset(cache, -1, sizeof(cache));
		cout << solve(0) << '\n';
	}	
}

