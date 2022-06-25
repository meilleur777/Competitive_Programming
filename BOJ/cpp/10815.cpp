#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> A;

bool have(int x) {
	int left = 0, right = N;
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (A[mid] == x) {
			return true;
		}
		else if (A[mid] < x) {
			left = mid + 1; 
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}	
	
	sort(A.begin(), A.end());
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		
		cout << have(x) << ' ';	
	}
	cout << '\n';
}

