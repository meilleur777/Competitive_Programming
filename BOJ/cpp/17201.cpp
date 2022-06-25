#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	string A; cin >> A;
	for (int i = 1; i < 2 * N; i += 2) {
		if (A[i] == A[i + 1]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}

