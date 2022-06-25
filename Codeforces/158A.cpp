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
	
	int n, k;
	cin >> n >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] >= A[k - 1] && A[i] > 0) {
			ans++;
		}
	}
	cout << ans << '\n';
}

