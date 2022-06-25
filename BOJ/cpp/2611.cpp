#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int choice[1001];
int cache[1001];
int dist[1001];
vector<pair<int, int> > edges[1001];

int solve(int S) {
	if (S == 1) {
		return dist[S];
	}
	
	int& ret = cache[S];
	if (ret != -1) return ret;
	
	for (auto i : edges[S]) {
		int temp = solve(i.first) + i.second;
		if (ret < temp) {
			ret = temp;
			choice[S] = i.first;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1 , sizeof(cache));
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		
		if (q == 1) dist[p] = r;
		
		edges[p].push_back({ q, r });
	}
	
	int result = -1;
	for (auto i : edges[1]) {
		int temp = solve(i.first) + i.second;
		if (temp > result) {
			result = temp;
			choice[1] = i.first;
		}
	}
			
	cout << result << '\n';
	
	vector<int> ans;	
	ans.push_back(1);
	int temp = choice[1];
	while (temp != 1) {
		ans.push_back(temp);
		temp = choice[temp];
	}
	ans.push_back(1);
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

