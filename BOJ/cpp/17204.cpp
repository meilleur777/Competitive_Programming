#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K, aim[152], result = -1;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> aim[i];
	for (int M = 1; M <= N; M++) {
		int temp = aim[0], count = M - 1;
		while (count--) temp = aim[temp];
		if (temp == K) {
			result = M;
			break;
		}	
	}	
	cout << result << '\n';
}

