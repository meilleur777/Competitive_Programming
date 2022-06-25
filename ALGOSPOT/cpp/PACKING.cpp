#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	string name;
	int volume;
	int need;
} item;	

int N;
int cache[1001][101];
vector<item> items;

/*남은 용량이 capacity일 때 current 이후의 물건들로 만들 수 있는 최대 가치의 합 반환*/
int pack(int capacity, int current) {
	if (current == N) return 0;
	
	int& ret = cache[capacity][current];
	if (ret != -1) return ret;
	
	ret = pack(capacity, current + 1);
	if (capacity >= items[current].volume)
		ret = max(ret, 
		pack(capacity - items[current].volume, current + 1) + items[current].need);
	return ret;
}

/*picked(capacity, current)가 선택한 물건들을 picked에 저장*/
void reconstruct(int capacity, int current, vector<string>& picked) {
	if (current == N) return;
	
	/*current를 고려하였으나 capacity의 변화가 없음, 즉 current는 선택되지 못함*/
	if (pack(capacity, current) == pack(capacity, current + 1)) {
		reconstruct(capacity, current + 1, picked);
	} 
	else {
		picked.push_back(items[current].name);
		reconstruct(capacity - items[current].volume, current + 1, picked);
	} 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		items.clear();
		memset(cache, -1, sizeof(cache));
		
		int W; cin >> N >> W;
		for (int i = 0; i < N; i++) {
			string a; int b, c; cin >> a >> b >> c;
			items.push_back({ a, b, c });
		}
		vector<string> picked;
		int result = pack(W, 0);
		reconstruct(W, 0, picked);
		cout << result << ' ' << picked.size() << '\n';
		for (auto i : picked) cout << i << '\n';
	}	
}

