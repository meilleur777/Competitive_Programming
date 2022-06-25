#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<vector<pair<int, string> > > name(21);

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		name[temp.size()].push_back({ i, temp });
	}	
	
	ll ans = 0;
	for (int i = 2; i <= 20; i++) {
		if (name[i].size() <= 1) continue;
		
		sort(name[i].begin(), name[i].end(), cmp);		
		int ceil = name[i][name[i].size() - 1].first;
		
		for (int j = 0; j < name[i].size() - 1; j++) {
			int temp = 
			upper_bound(name[i].begin() + j + 1, name[i].end(), 
			make_pair(min(ceil, name[i][j].first + K), string(21, 'Z')), cmp) - (name[i].begin() + j + 1);
						
			ans += temp;
		}
	}
	cout << ans;
}

