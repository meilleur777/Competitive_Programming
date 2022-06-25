#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	string numA, numB;
	getline(cin, numA);
	getline(cin, numB);
	char lastWin = 'D';
	int winA = 0, winB = 0;
	
	for (int i = 0; i < numA.size(); i += 2) {
		if (numA[i] > numB[i]) {
			winA += 3;
			lastWin = 'A';
		}
		else if (numA[i] == numB[i]) {
			winA++;
			winB++;
		}
		else {
			winB += 3;
			lastWin = 'B';
		}
	}
	
	cout << winA << ' ' << winB << '\n';
	if (winA > winB) cout << 'A' << '\n';
	else if (winB > winA) cout << 'B' << '\n';
	else cout << lastWin << '\n';
}

