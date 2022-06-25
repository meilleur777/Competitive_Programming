#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int high[10001];
int parent[10001];
int size[10001];
int enemy[10001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

int merge(int a, int b) {
	if (a == -1 || b == -1) return max(a, b);
	
	a = find(a); b = find(b);
	
	if (a == b) return a;
	
	if (high[a] > high[b]) swap(a, b);
	
	if (high[a] == high[b]) high[b]++;
	parent[a] = b;
	size[b] += size[a];
	return b;
}

bool dis(int u, int v) {
	u = find(u), v = find(v);
	
	if (u == v) return false;
	
	int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
	enemy[a] = b, enemy[b] = a;
	return true;
}

bool ack(int u, int v) {
	u = find(u), v = find(v);
	
	if (enemy[u] == v) return false;
	
	int a = merge(u, v), b = merge(enemy[u], enemy[v]);
	enemy[a] = b;
	
	if (b != -1) enemy[b] = a;
	return true;
}

int maxParty() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (parent[i] == i) {
			int temp = enemy[i];
			
			if (temp > i) continue;
			
			int mySize = size[i];
			int enemySize = (temp == -1 ? 0 : size[temp]);
			
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C;
	cin >> C;
	while (C--) {
		int M;
		cin >> N >> M;
		
		fill_n(high, 10001, 1);		
		fill_n(size, 10001, 1);
		fill_n(enemy, 10001, -1);
		
		int firCon = 0;
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		
		for (int i = 1; i <= M; i++) {
			int a, b;
			string temp;
			cin >> temp >> a >> b;
				
			if (firCon) continue;
				
			if (temp == "ACK") {
				if (!ack(a, b)) {
					firCon = i;
				}				
			}
			else if (temp == "DIS") {
				if (!dis(a, b)) {
					firCon = i;
				}
			}
		}
		
		if (firCon) {
			cout << "CONTRADICTION AT " << firCon << '\n';
		}
		else {
			cout << "MAX PARTY SIZE IS " << maxParty() << '\n';
		}
	}
}

