#include <iostream>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		int resultx, resulty;
		int checkx[1001] = { 0 }, checky[1001] = { 0 };
		for (int i = 0; i < 3; i++) {
			int x, y; cin >> x >> y;
			checkx[x]++, checky[y]++;
		}
		for (int i = 1; i <= 1000; i++) {
			if ((checkx[i] % 2) == 1) resultx = i;
			if ((checky[i] % 2) == 1) resulty = i;
		}
		cout << resultx << ' ' << resulty << '\n';
		
	}	
}

