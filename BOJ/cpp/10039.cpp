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
		
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		
		ans += max(40, x);
	}
	cout << ans / 5;
}

