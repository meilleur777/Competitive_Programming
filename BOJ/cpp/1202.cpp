#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*무게가 가벼운 가방부터 채우기 시작하는데, 가방에 넣을 수 있는 가장 비싼 보석을 고르면 된다.*/

int bag[300001];
vector<pair<int, int> > v;
priority_queue<int> pq;	/*가치가 큰 것이 위로*/

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int M, V; scanf("%d %d", &M, &V);
		v.push_back(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) scanf("%d", &bag[i]);
	
	sort(v.begin(), v.end());
	sort(bag, bag + K); 
	
	int j = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && v[j].first <= bag[i]) pq.push(v[j++].second);
		if (!pq.empty()) { sum += pq.top(); pq.pop(); }
	}
	printf("%d\n", sum);
}

