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
	
	if (!N) {
		cout << 1;
		return 0;
	}
	
	int cnt[10] = { 0 };
	while (N) {
		cnt[N % 10]++;
		N /= 10;
	}	
	
	int temp = cnt[6] + cnt[9];
	if (temp % 2) {
		cnt[6] = temp / 2;
		cnt[9] = cnt[6] + 1;
	}
	else {
		cnt[6] = cnt[9] = temp / 2;
	}
	
	int ans = -1;
	for (int i = 0; i < 10; i++) {
		ans = max(ans, cnt[i]);
	}
	cout << ans;
}

