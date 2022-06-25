#include <vector>
#i
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

const ll mod = 1e9 + 7;

vector<int> tree;

/*
4
199998 200000
199999 199999
200000 200000
199999 200000
*/

bool cpr(p a, p b) {
	return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}

void update(int index, int x) {
	for (; index < tree.size(); index += (index & -index)) {
		tree[index] += x;
	}
}

int sum(int index) {
	int result = 0;
	for (; index > 0; index &= (index - 1)) {
		result += tree[index];
	}
	return result;
}

int countStar(int start, int end) {
	return sum(end) - sum(start - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<p> star(N);
	
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		
		star[i] = { x, y };
	}	
	
	tree.resize(400000 + 2);
	fill_n(tree.begin(), tree.size(), 0);
	sort(star.begin(), star.end(), cpr);
	
	for (int i = 0; i < N; i++) {
		update(star[i].first + 1 + 200000, 1);
	}
	
	int res = 0;
	int remem = INT_MAX;
	for (int i = 0; i < N; i++) {
		/*새로운 층에 왔으면 그 층의 별을 모두 지운다.*/
		if (star[i].second != remem) {
			int target = i;
			remem = star[i].second; 
			while (target < N && star[i].second == star[target].second) {
				update(star[target].first + 1 + 200000, -1);
				target++;
			}
		}
		
		ll left = countStar(1, star[i].first + 200000);
		ll right = countStar(star[i].first + 200002, 400001);
		
		res += (left * right) % mod;
		res %= mod;
		
		//cout << left << ' ' << right << '\n';
		//cout << star[i].first << ' ' << star[i].second << '\n';
		//cout << left * right << " plused" << '\n';
	}
	cout << res << '\n';
}

