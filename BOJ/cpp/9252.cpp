#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

string A, B;
int cache[1001][1001];
	
/*A문자열을 a - 1, B문자열을 b - 1까지 보았을 때 
앞으로 남은 문자열에서 얻을 수 있는 최대 길이 반환*/
int solve(int a, int b) {
	if (a == A.size() || b == B.size()) return 0;
	
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	
	ret = 0;
	
	if (A[a] == B[b]) return ret = 1 + solve(a + 1, b + 1);
	
	int cana = solve(a + 1, b);
	int canb = solve(a, b + 1);
	if (cana > canb) return ret = cana;
	if (cana <= canb) return ret = canb;
}

void reconstruct(int a, int b, vector<char>& result) {
	if (a == A.size() || b == B.size()) return;
	if (A[a] == B[b]) {
		result.push_back(A[a]);
		reconstruct(a + 1, b + 1, result);
		return;
	}
	if (solve(a + 1, b) > solve(a, b + 1)) reconstruct(a + 1, b, result);
	else reconstruct(a, b + 1, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<char> result;
	memset(cache, -1, sizeof(cache));
	
	cin >> A >> B;
	cout << solve(0, 0) << '\n';
	reconstruct(0, 0, result);
	if (!result.empty()) for (auto i : result) cout << i;
}

