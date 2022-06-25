#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	int A[101];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	
	int ans[101];
	for (int i = 1; i <= N; i++) {
		ans[i] = i;
	}
	
	for (int i = 1; i <= N; i++) {
		int j = i;
		while (A[i]) {
			swap(ans[j - 1], ans[j]);
			j--;
			A[i]--;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}	

