#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, Q;
	cin >> N >> Q;	
	vector<int> A(N), psum(N + 1);
	psum[0] = 0;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] +  abs(A[i] - A[i - 1]);
	while (Q--) {
		int a, b; cin >> a >> b;
		cout << psum[b - 1] - psum[a - 1] << '\n';
	}
}

