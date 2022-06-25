#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	if (!(a % b)) return b;
	else return GCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}	
	sort(A.begin(), A.end());
	
	int gcd = A[1] - A[0];
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, A[i] - A[i - 1]);
	}
	
	vector<int> result;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i) continue;
		
		result.push_back(i);
		result.push_back(gcd / i);
	}
	result.push_back(gcd);
	
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	
	for (auto i : result) {
		cout << i << ' ';
	}
	cout << '\n';
}

