#include <iostream>
#include <string>
#include <map>
using namespace std;

/*Disjoint Set*/

map<string, int> m;
int size[200001], parent[200001];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	else if (a < b) {
		parent[b] = a;
		size[a] += size[b];
	}
	else {
		parent[a] = b;
		size[b] += size[a];
	}
}


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		m.clear();
		int F, num = 1;
		cin >> F;
		for (int i = 1; i <= 2 * F; i++) {
			parent[i] = i;
			size[i] = 1;
		}
		
		for (int i = 1; i <= F; i++) {
			int friend1, friend2;
			string name1, name2;
			cin >> name1 >> name2;
			
			auto temp = m.find(name1);
			if (temp == m.end()) {
				m[name1] = num++;
				friend1 = num - 1;
			}
			else friend1 = temp->second;
			
			temp = m.find(name2);
			if (temp == m.end()) {
				m[name2] = num++;
				friend2 = num - 1;
			}
			else friend2 = temp->second;
			
			merge(friend1, friend2);
			cout << size[find(friend1)] << "\n";
		}
	}
}

