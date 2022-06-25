#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

bool compare(p a, p b) { 
	return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second); 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		vector<p> v;
		int N, M; cin >> N >> M;
		bool selected[1002] = { false };
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a, b });
		} 
		sort(v.begin(), v.end(), compare);
		
		int count = 0;
		for (auto i : v) {
			for (int j = i.first; j <= i.second; j++) {
				if (!selected[j]) {
					selected[j] = true;
					count++;
					break;
				}
			}
		}
		cout << count << '\n';
	}
}

