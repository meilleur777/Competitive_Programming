#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
vector<p> A;

bool cpr(p a, p b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N; A.resize(N);
	for (p& i : A) cin >> i.first >> i.second;
	sort(A.begin(), A.end(), cpr);
	
	int left = A[0].first, right = A[0].second, length = right - left;
	for (int i = 1; i < N; i++) {
		if (A[i].first > right) {
			left = A[i].first, right = A[i].second;
			length += right - left;
		}
		else if (A[i].second > right) {
			length += A[i].second - right;
			right = A[i].second;
		}
	}
	cout << length << '\n';
}

