#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		string word;
		cin >> word;
		
		
		vector<char> odd, even;
		for (int i = 0; i < word.size(); i++) {
			if (i % 2) odd.push_back(word[i]);
			else even.push_back(word[i]);
		}
		
		for (auto i : even) cout << i;
		for (auto i : odd) cout << i;
		cout << '\n';
	}	
}

