#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int A[2][100003];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
	
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin >> A[i][j];
			}
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i < m; i++) {
			sum1 += A[0][i];
		}
		
		int ans = sum1;
		for (int i = 1; i < m; i++) {
			sum1 -= A[0][i];
			sum2 += A[1][i - 1];
			
			ans = min(ans, max(sum1, sum2));
		}
				
		cout << ans << '\n';
	}	
}

