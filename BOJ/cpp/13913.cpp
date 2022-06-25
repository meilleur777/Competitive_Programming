#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int trace[100001];

int main() {
	int N, K; scanf("%d %d", &N, &K);
	int result;	
	memset(trace, -1, sizeof(trace));
	
	queue<p> q;
	q.push({N, 0});
	trace[N] = -3;
	
	while(!q.empty()) {
		int loc = q.front().first, time = q.front().second;
		if (loc == K) { result = time; break; }
		q.pop();
		
		int temp;
		if ((temp = loc - 1) >= 0 && trace[temp] == -1) {
			q.push({temp, time + 1});
			trace[temp] = loc;
		}
		if ((temp = loc + 1) <= 100000 && trace[temp] == -1) {
			q.push({temp, time + 1});
			trace[temp] = loc;
		}
		if ((temp = 2 * loc) <= 100000 && trace[temp] == -1) {
			q.push({temp, time + 1});
			trace[temp] = loc;
		}
	}
  	
  	vector<int> answer;
  	while (K != -3) {
  		answer.push_back(K);
		K = trace[K];
	}
	
	printf("%d\n", result);
	for (auto i = answer.end() - 1; i > answer.begin(); i--) {
		printf("%d ", *i);
	}  	
	printf("%d\n", *answer.begin());
}

