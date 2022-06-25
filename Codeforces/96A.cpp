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
		
	string temp;
	cin >> temp;
	
	int count = 1;
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i - 1] == temp[i]) {
			count++;
			if (count >= 7) {
				cout << "YES\n";
				return 0;
			}
		}
		else {
			count = 1;
		}
	}
	cout << "NO";
}

