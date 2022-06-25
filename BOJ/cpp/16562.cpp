#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int A[10001];
int parent[10001];
bool visit[10001] = { false };

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	
	if (A[a] > A[b]) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, k;
	cin >> N >> M >> k;
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		parent[i] = i;
	}	
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int temp = find(i);
		
		if (!visit[temp]) {
			visit[temp] = true;
			k -= A[temp];
			sum += A[temp];
			
			if (k < 0) {
				cout << "Oh no\n";
				return 0;
			}
		}
	}
	cout << sum << '\n';
}

