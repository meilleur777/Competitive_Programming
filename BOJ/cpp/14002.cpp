#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> A;
int cache[1002];
int choice[1002];

/*A[a]부터 끝까지 보았을 때 LIS의 길이 반환*/
int solve(int a) {
	int& ret = cache[a + 1];
	if (ret != -1) return ret;
	
	int& choose = choice[a + 1];
	ret = 0; choose = -1;
	
	for (int i = a + 1; i < N; i++) {
		if (a == -1 || A[a] < A[i]) {
			int temp = solve(i);
			if (temp + 1 > ret) {
				ret = temp + 1;
				choose = i;
			}
		}
	}	
	return ret;
}

void reconstruct(int a, vector<int>& result) {
	if (a != -1) result.push_back(A[a]);
	int choose = choice[a + 1];
	if (choose != -1) reconstruct(choose, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a; A.push_back(a);
	}
	cout << solve(-1) << '\n';
	vector<int> result;
	reconstruct(-1, result);
	for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
	cout << '\n';
}

