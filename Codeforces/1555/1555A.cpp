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
	
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		if (N % 2) N++;
		
		ll ans;		
		if (N <= 6) {
			ans = 15;
		}
		else if (N <= 8) {
			ans = 20;
		}
		else if (N <= 10) {
			ans = 25;
		}
		else {
			ans = N * 5;
			ans /= 2;
		}
		cout << ans << '\n';
	}
}

