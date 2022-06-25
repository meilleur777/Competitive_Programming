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
	
		int k;
		cin >> k;
		
		int temp = (k - 1) / 18;
		int ans = temp * 30;
		
		k %= 18;
		if (!k) k = 18;
		
		int cnt = 0;
		for (int i = 1; i <= 30; i++) {
			if (i % 3 && i % 10 != 3) {
				cnt++;
				if (cnt == k) {
					ans += i;
					break;
				}
			}
		}
		
		cout << ans << '\n';
	}	
}

