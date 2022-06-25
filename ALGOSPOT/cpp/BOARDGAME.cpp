#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int NEGINF = -987654321;
int n, num[51], cache[51][51]; 

/*숫자가 left~right 남았을 때, max(이번 차례 참가자 점수 - 다른 참가자 점수) 반환*/
int solve(int left, int right) {
	if (left > right) return 0;
	
	int& ret = cache[left][right];
	if (ret != NEGINF) return ret;
	
	ret = max(num[right] - solve(left, right - 1), num[left] - solve(left + 1, right));
	if (right - left + 1 >= 2) {
		ret = max(ret, -solve(left + 2, right));
		ret = max(ret, -solve(left, right - 2));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> n;
		fill_n(&cache[0][0], 51 * 51, NEGINF);
		for (int i = 0; i < n; i++) cin >> num[i];
		cout << solve(0, n - 1) << '\n';
	} 
}

