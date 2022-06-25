#include <stdio.h>
#include <set>

using namespace std;

multiset<int> s;

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			char c; int n; scanf(" %c %d", &c, &n);
			
			if (c == 'I') s.insert(n);
			else if (c == 'D' && !s.empty()) {
				if (n == 1) {
					auto t = s.end();
					s.erase(--t);
				}
				else s.erase(s.begin());
			} 
		}
		
		if (s.empty()) printf("EMPTY\n");
		else {
			auto t = s.end();
			printf("%d %d\n", *(--t), *s.begin());
		}
		s.clear();
	}
}

