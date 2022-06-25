#include <stdio.h>
#include <vector>
#include <algorithm>
#define NUM 100001
using namespace std;

typedef struct {
	int a, b;
} line;

line lines[NUM];
bool check[NUM] = { false };
int index[NUM];  
vector<int> v { 0 };

bool cpr(line m, line n) {
	return m.a < n.a;
}

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b; scanf("%d %d", &a, &b);
		lines[i] = { a, b };		
	}
	sort(lines, lines + N, cpr);
	
	for (int i = 0; i < N; i++) {
		if (v.back() < lines[i].b) {
			v.push_back(lines[i].b);
			index[i] = v.size() - 2;
		}
		else {
			int t = lower_bound(v.begin(), v.end(), lines[i].b) - v.begin();
			index[i] = t - 1;
			v[t] = lines[i].b;
		}
	}	
	
	int temp = v.size() - 2;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == temp) {
			check[i] = true;
			temp--;
		}
	}
	
	printf("%d\n", N - v.size() + 1);
	for (int i = 0; i < N; i++) 
		if (!check[i]) printf("%d\n", lines[i].a);
}

