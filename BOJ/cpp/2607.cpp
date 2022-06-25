#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	string word;
	cin >> word;
	
	int cntW[30] = { 0 };
	for (auto i : word) {
		cntW[i - 'A']++;
	}
	
	int ans = 0;
		string temp;
	for (int i = 1; i < N; i++) {
		cin >> temp;
		
		int cntT[30] = { 0 };
		for (auto j : temp) {
			cntT[j - 'A']++;
		}
		
		int count = 0;
		int check[2];	
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			int cnta = abs(cntT[i] - cntW[i]);
			if (cnta == 1) {
				count++;
			}
			else if (cnta >= 2) {
				flag = false;
				break;
			}	
		}
		
		if (!flag) {
			continue;
		}
		if (count > 2) continue;
		else if (count == 2) {
			if (abs((int)word.size() - (int)temp.size()) == 0) {
				ans++;
			}
		}
		else ans++;
	}	
	
	cout << ans << '\n';
}

