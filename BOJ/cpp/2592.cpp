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
	
	int x;
	int cnt[101] = { 0 }, sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		cnt[x / 10]++;
		sum += x;
	}	
	
	int maxV = -1;
	int ans;
	for (int i = 1; i < 100; i++) {
		if (maxV < cnt[i]) {
			ans = i;
			maxV = cnt[i];
		}
	}
	
	cout << sum / 10 << '\n';
	cout << ans * 10 << '\n';
}

