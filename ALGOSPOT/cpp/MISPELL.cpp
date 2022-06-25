#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, i = 1;	
	cin >> N;
	while (N--) {
		int M;
		string word;
		bool check[100] = { false };
		
		cin >> M >> word;
		check[M - 1] = true;
		
		cout << i << ' ';
		i++;
		
		for (int j = 0; j < word.size(); j++) {
			if (check[j]) continue;
			cout << word[j];
		}
		cout << '\n';
	}
}

