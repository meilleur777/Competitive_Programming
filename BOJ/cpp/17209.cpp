#include <vector>
#include <iostream>
using namespace std;

int A, B;
vector<vector<int> > edges;
bool visit[2002] = { false };

void DFS(int S, bool a) {
	visit[S] = true;
	if (a) A++; else B++;
	for (auto i : edges[S]) if (!visit[i]) DFS(i, !a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N; edges.resize(N);
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < N; j++) {
			if (temp[j] == '1') {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			A = B = 0;
			DFS(i, false);
			result += max(A, B);				
		}
	}
	cout << result << '\n';
}

