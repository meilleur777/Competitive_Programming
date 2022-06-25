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
	
	int y, x, maxValue = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int k;
			cin >> k;
			
			if (k > maxValue) {
				maxValue = k;
				y = i, x = j;
			}
		}
	}	
	
	cout << maxValue << '\n';
	cout << y + 1 << ' ' << x + 1;
}

