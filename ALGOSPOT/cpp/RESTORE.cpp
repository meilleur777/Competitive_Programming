#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#define NUM 15
using namespace std;

int k;
string words[NUM];
bool jump[NUM] = { false }; /*어떤 문자열이 다른 문자열에 포함되면 jump*/
int overlap[NUM][NUM], cache[NUM][1 << NUM], choice[NUM][1 << NUM];

/*마지막 조각이 last이고, 지금까지 used를 사용했을 때 앞으로 남은 문자열들을
추가하여 얻을 수 있는 overlap의 최대값 반환*/
int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	
	int& ret = cache[last][used];
	int& choose = choice[last][used];
	if (ret != -1) return ret;
	
	for (int next = 0; next < k; next++) {
		if (jump[next] || used & (1 << next)) continue;
		int temp = overlap[last][next] + restore(next, used | (1 << next));
		if (ret < temp) { ret = temp; choose = next; }
	}
	return ret;
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	int choose = choice[last][used];
	return (words[choose].substr(overlap[last][choose]) + 
	reconstruct(choose, used | (1 << choose)));		
}

/*overlap[][]의 값 계산*/
void precalc() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i == j) continue;
			
			for (int l = 0; l <= words[i].size(); l++) {
				int compared = min(words[i].size() - l, words[j].size());
				if (words[i].substr(l, compared) == words[j].substr(0, compared)) {
					if (compared == words[j].size()) jump[j] = true;
					overlap[i][j] = compared;
					break;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--)	{
		cin >> k;
		for (int i = 0; i < k; i++) cin >> words[i];
		
		int base = 0;
		memset(cache, -1, sizeof(cache));
		memset(choice, -1, sizeof(choice));
		memset(jump, false, sizeof(jump));
		
		precalc();
		for (int i = 0; i < k; i++) if (jump[i]) base |= (1 << i);
		
		int resultIndex, resultValue = -1;
		for (int i = 0; i < k; i++) {
			if (jump[i]) continue;
 			if (resultValue < restore(i, base | (1 << i))) {
				resultValue = restore(i, base | (1 << i));
				resultIndex = i;
			}
		}
		
		string result = words[resultIndex] + 
		reconstruct(resultIndex, base | (1 << resultIndex));
		cout << result << '\n';
	}
}

