#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> trees;

int solve(int left, int right) {
	if (left == right) return trees[left];
	
	int mid = (left + right) / 2;
	int result = max(solve(left, mid) , solve(mid + 1, right));
	
	int lo = mid, hi = mid + 1;
	int height = min(trees[lo], trees[hi]);
	result = max(result, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (left == lo || trees[lo - 1] < trees[hi + 1])) 
			height = min(height, trees[++hi]);
		else height = min(height, trees[--lo]);
		result = max(result, height * (hi - lo + 1));
	}
	return result;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		trees.clear();
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			trees.push_back(a);
		}
		cout << solve(0, trees.end() - trees.begin() - 1) << '\n';		
	}
}

