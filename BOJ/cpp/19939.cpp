#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, k;
	cin >> N >> k;
	
	int temp = k*(k+1)/2;
	
	if (N < temp) {
		cout << -1;
		return 0;
	}
	else if (N == temp) {
		cout << k - 1;
		return 0;
	}
	else {
		N -= temp;
		N %= k;
			
		if (N == 0) {
			cout << k - 1;
		}
		else {
			cout << k;			
		}
	}
}

