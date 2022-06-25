#include <set> 
#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		int N, x; cin >> N;
		vector<int> russian(N), korean(N);
		for (int i = 0; i < N; i++) cin >> russian[i];
		for (int i = 0; i < N; i++) cin >> korean[i];
		multiset<int> ratings(korean.begin(), korean.end());
		
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (*ratings.rbegin() < russian[i]) ratings.erase(ratings.begin());
			else {
				ratings.erase(ratings.lower_bound(russian[i]));
				count++;
			}
		}
		cout << count << '\n';
	}
}

