#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
	
		switch (n % 3) {
			case 0:
				cout << n / 3 << ' ' << n / 3 << '\n';
				break;
			case 1:
				cout << n / 3 + 1 << ' ' << n / 3 << '\n';
				break;
			case 2:
				cout << n / 3 << ' ' << n / 3 + 1 << '\n';
		}		
	}	
}

