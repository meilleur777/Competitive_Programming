#include <vector>
#include <iostream>
using namespace std;

int N, M;
vector<int> A;

bool check(int K) {
	int temp = K, count = 1;
	
	for (int i = 0; i < N; i++) {
		if (K < A[i]) return false;
		
		if (temp < A[i]) {
			temp = K;
			count++;
		}
		temp -= A[i];	
	}
	
	return count <= M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	int result;	
	int left = 1, right = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (check(mid)) {
			right = mid - 1;
			result = mid;			
		}		
		else {
			left = mid + 1;
		}
	}
	
	cout << result << '\n';
}

