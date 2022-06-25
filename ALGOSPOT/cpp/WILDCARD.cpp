#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string W, S;
int cache[101][101];

int solve(int wptr, int sptr) {
	int& ret = cache[wptr][sptr];
	if (ret != -1) return ret;
	
	if (wptr < W.size() && sptr < S.size() && (W[wptr] == '?' || W[wptr] == S[sptr])) 
		return ret = solve(wptr + 1, sptr + 1);
	
	if (wptr == W.size()) return ret = (sptr == S.size());
	
	if (W[wptr] == '*') {
		if (solve(wptr + 1, sptr) == 1 || (sptr < S.size() && solve(wptr, sptr + 1) == 1))
			return ret = 1;		
	}	
	
	return ret = 0;	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		int N; 
		vector<string> result;
		cin >> W >> N;
		for (int i = 0; i < N; i++) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (solve(0, 0) == 1) result.push_back(S);
		}
		sort(result.begin(), result.end());
		for (auto i : result) cout << i << '\n';
	}	
}

