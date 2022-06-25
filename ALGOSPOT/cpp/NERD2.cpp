#include <map>
#include <iostream>
using namespace std;

typedef map<int, int>::iterator mit;

map<int, int> coords;
int N, p[100001], q[100001];

bool isDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) return false;
 	return y < it->second;
}

void removeDominated(int x, int y) {
	mit it = coords.lower_bound(x);
	if (it == coords.begin()) return;
	it--;
	
	while (true) {
		if (y < it->second) break;
		
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			mit jt = it; jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

int solve() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (!isDominated(p[i], q[i])) {
			removeDominated(p[i], q[i]);
			coords.insert({ p[i], q[i] });
		}
		sum += coords.size();		
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> N;
		coords.clear();
		for (int i = 0; i < N; i++) cin >> p[i] >> q[i];
		cout << solve() << '\n';
	}	
}

