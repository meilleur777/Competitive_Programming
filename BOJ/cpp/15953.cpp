#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int A[7] = { 0 };
	for (int i = 1; i <= 6; i++) {
		A[i] = A[i - 1] + i;
	}
	
	int B[6] = { 0 };
	for (int i = 1; i <= 5; i++) {
		B[i] = B[i - 1] + (1 << (i - 1));
	}
	
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		
		ll ans = 0;
		if (a != 0) {
			if (a <= A[1]) ans += 500;
			else if (a <= A[2]) ans += 300;
			else if (a <= A[3]) ans += 200;
			else if (a <= A[4]) ans += 50;
			else if (a <= A[5]) ans += 30;
			else if (a <= A[6]) ans += 10;
		}		
		if (b != 0) {
			if (b <= B[1]) ans += (1 << 9);
			else if (b <= B[2]) ans += (1 << 8);
			else if (b <= B[3]) ans += (1 << 7);
			else if (b <= B[4]) ans += (1 << 6);
			else if (b <= B[5]) ans += (1 << 5);
		}
		cout << ans * 10000 << '\n';
	}	
}

