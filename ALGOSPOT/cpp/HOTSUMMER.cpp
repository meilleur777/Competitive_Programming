#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int W;
		cin >> W;
		
		int sum = 0;
		for (int i = 9; i < 18; i++) {
			int x;
			cin >> x;
			sum += x;
		}
				
		if (sum <= W) cout << "YES\n";
		else cout << "NO\n";
	}	
}

