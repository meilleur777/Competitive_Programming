#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int parent[MAX];
bool visit[MAX];
queue<int> que;
vector<int> edge[MAX];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; 
		cin >> a >> b;	
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	parent[1] = 0;
	visit[1] = true;
	que.push(1);
	
	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		
		for (int i : edge[temp]) {
			if (!visit[i]) {
				visit[i] = true;
				parent[i] = temp;
				que.push(i);
			}
		}
	}
	
	for (int i = 2; i <= N; i++) cout << parent[i] << "\n";
}
