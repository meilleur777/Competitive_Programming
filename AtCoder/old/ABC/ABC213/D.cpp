#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

vector<int> edges[200001];
vector<int> child[200001];

void traverse(int S) {
	cout << S << ' ';
	for (auto i : child[S]) {
		traverse(i);
		cout << S << ' ';
	}
}

bool visit[200001] = { false };

void makeTree(int S) {
	for (auto i : edges[S]) {
		if (!visit[i]) {
			visit[i] = true;
			child[S].push_back(i);
			makeTree(i);
		}
	}
	
	sort(child[S].begin(), child[S].end());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}	
	
	visit[1] = true;
	makeTree(1);
	traverse(1);	
}

