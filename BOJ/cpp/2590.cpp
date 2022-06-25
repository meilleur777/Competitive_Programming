#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int A[7];
	for (int i = 1; i <= 6; i++) {
		cin >> A[i];
	}	
	
	int ans = A[6];
	
	ans += A[5];
	A[1] -= A[5] * 11;
	A[1] = max(0, A[1]);
	
	ans += A[4];
	int temp = A[2];
	A[2] -= A[4] * 5;
	A[2] = max(0, A[2]);
	
	A[1] -= A[4] * 20 -	4 * min(temp, A[4] * 5);
	A[1] = max(0, A[1]);
	
	ans += A[3] / 4;
	A[3] %= 4;
	switch (A[3]) {
		case 1:
			ans++;
			temp = A[2];
			A[2] -= 5;
			A[2] = max(0, A[2]);
			A[1] -= 27 - min(5, temp) * 4;
			A[1] = max(0, A[1]);
			break;
		case 2:
			ans++;
			temp = A[2];
			A[2] -= 3;
			A[2] = max(0, A[2]);
			A[1] -= 18 - min(3, temp) * 4;
			A[1] = max(0, A[1]);
			break;
		case 3:
			ans++;
			temp = A[2];
			A[2] -= 1;
			A[2] = max(0, A[2]);
			A[1] -= 9 - min(1, temp) * 4;
			A[1] = max(0, A[1]);
			break;
	}
	
	ans += A[2] / 9;
	A[2] %= 9;
	if (A[2] > 0) {
		ans++;
		A[1] -= 36 - A[2] * 4;
		A[1] = max(0, A[1]);
	}
	
	ans += A[1] / 36;
	A[1] %= 36;
	if (A[1] > 0) {
		ans++;
	}
	
	cout << ans << '\n';
}

