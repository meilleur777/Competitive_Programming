#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, H;
vector<int> A;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> H;	
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	vector<int> countOdd(H + 1, 0), countEven(H + 1, 0);
	
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			countOdd[H - A[i] + 1]++;
		}
		else {
			countEven[A[i]]++;
		}
	}
	
	for (int i = H; i > 1; i--) {
		countEven[i - 1] += countEven[i]; 
	}
	for (int i = 1; i < H; i++) {
		countOdd[i + 1] += countOdd[i];
		countEven[i + 1] += countOdd[i + 1];
	}
	countEven[1] += countOdd[1];
	
	sort(countEven.begin() + 1, countEven.end());
	int result = upper_bound(countEven.begin() + 1, countEven.end(), countEven[1]) -
	lower_bound(countEven.begin() + 1, countEven.end(), countEven[1]);
	cout << countEven[1] << ' ' << result << '\n';
}

