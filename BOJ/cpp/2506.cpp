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
	
	int N;
	cin >> N;
	int memo = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			memo++;
			ans += memo;
		}
		else {
			memo = 0;
		}
	}	
	cout << ans;
}

