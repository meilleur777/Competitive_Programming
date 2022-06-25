#include <vector>
#include <math.h>
#include <string>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<bool> cand(1000, false);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 123; i <= 999; i++) {
		string temp = to_string(i);
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') continue;
		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0]) continue;
		cand[i] = true;
	}
	
	while (N--) {
		string num;
		cin >> num;
		
		int stk, bal;
		cin >> stk >> bal;
		
		for (int k = 123; k <= 999; k++) {
			if (!cand[k]) continue;
			
			string temp = to_string(k);
			
			int tstk = 0, tbal = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (temp[i] == num[j]) {
						if (i == j) tstk++;
						else tbal++;
					}	
				}
			}	
			
			if (stk == tstk && bal == tbal) continue;
			cand[k] = false;
		}
	}
	
	int ans = 0;
	for (int i = 123; i <= 999; i++) {
		ans += cand[i];
	}
	cout << ans;
}

