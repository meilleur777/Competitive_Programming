#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int sum = 0, dwarfs[10];	
	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}
	sort(dwarfs, dwarfs + 9);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - dwarfs[i] - dwarfs[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << dwarfs[k] << '\n';
				}
				return 0;
			}
		}
	}
}

