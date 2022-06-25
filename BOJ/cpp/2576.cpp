#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> answer;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		int x; scanf("%d", &x);
		if (x % 2) answer.push_back(x);
	}
	if (answer.empty()) printf("-1\n");
	else {
		for (auto i : answer) sum += i;
		printf("%d\n%d\n", sum, *min_element(answer.begin(), answer.end()));
	}
}

