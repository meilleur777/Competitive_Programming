#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int letcnt[200001][5];
vector<string> words;

int solve(int alpha) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			if (j == alpha) continue;
			sum += letcnt[i][j];
		}
		v.push_back(sum - letcnt[i][alpha]);
	}
	sort(v.begin(), v.end());
	
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		if (sum >= 0) return i;
	}
	return v.size();	
}

void precalc() {
	for (int i = 0; i < n; i++) {
		for (auto j : words[i]) {
			letcnt[i][j - 'a']++;
		}
	}		
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		
		memset(letcnt, 0, sizeof(letcnt));
		
		words.clear();
		words.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		
		precalc();
		
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			ans = max(ans, solve(i));
		}		
		cout << ans << "\n";
	}
}

