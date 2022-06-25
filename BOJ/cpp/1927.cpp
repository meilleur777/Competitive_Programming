#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void ins(int x) {
	int now=heap.size();
	heap.push_back(x);
	while (now!=0 && x<heap[(now-1)/2]) {
		heap[now]=heap[(now-1)/2];
		now=(now-1)/2;
	}
	heap[now]=x;
}

int del() {
	if (heap.empty()) return 0;

	int ret=heap[0];
	heap[0]=heap.back();
	heap.pop_back();

	if (heap.empty()) return ret;

	int now=0;
	int memo=heap[0];
	while (true) {
		int left=now*2+1;
		int right=left+1;
		int child;
		if (right<heap.size()) {
			child=heap[left]<heap[right]?left:right;
		}
		else if (right==heap.size()) {
			child=left;
		}
		else {
			break;
		}

		if (memo>heap[child]) {
			heap[now]=heap[child];
			now=child;
		}
		else break;
	}
	heap[now]=memo;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x==0) cout << del() << '\n';
		else ins(x);
	}

	return 0;
}
