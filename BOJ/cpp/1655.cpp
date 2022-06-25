#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

int main() {
	int N; scanf("%d", &N);
	while (N--) {
		int x; scanf("%d", &x);
		
		if (maxheap.size() == minheap.size()) maxheap.push(x);
		else minheap.push(x);
		
		if (!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()) {
			int a = maxheap.top(), b = minheap.top();
			maxheap.pop(), minheap.pop();
			maxheap.push(b), minheap.push(a);
		}
		
		printf("%d\n", maxheap.top());
	}
}

