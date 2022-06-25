#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		
		int alcnt[30] = { 0 };
		
		for (auto i : s) {
			alcnt[i - 'a']++;
		}
		
		int count = 0;
		for (int i = 0; i < 26; i++) {
			if (alcnt[i] >= 2) {
				count += 2;
			}
			else if (alcnt[i] == 1) {
				count++;
			}
			
		}
		
		cout << count / 2 << '\n';
	}	
}

