#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int sqr(int a) {
	return a * a;
}

int dist(p a, p b) {
	return sqr(a.first - b.first) + sqr(a.second - b.second);
}	

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	
	while (T--) {
		p start, end;
		
		cin >> start.first >> start.second >> end.first >> end.second;
		
		int n;
		cin >> n;
		
		vector<p> pla(n);
		vector<int> R(n);
		
		for (int i = 0; i < n; i++) {
			cin >> pla[i].first >> pla[i].second >> R[i];				
		}
		
		
		bool instart[51] = { false }, inend[51] = { false };
		for (int i = 0; i < n; i++) {
			if (dist(pla[i], start) < sqr(R[i])) {
				instart[i] = true;
			}
			
			if (dist(pla[i], end) < sqr(R[i])) {
				inend[i] = true;
			}
		}
		
		int count = 0;
		for (int i = 0; i < n; i++) {
			if ((instart[i] && !inend[i]) || (!instart[i] && inend[i])) {
				count++;
			}
		}
		
		cout << count << '\n';
	}	
}

