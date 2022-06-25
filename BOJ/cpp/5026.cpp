#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	while (N--)	 {
		string temp;
		cin >> temp;
		
		if (temp[0] >= '0' && temp[0] <= '9') {
			int index;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == '+') {
					index = i;
					break;
				}
			}
			
			string as = string(temp.begin(), temp.begin() + index);
			string bs = string(temp.begin() + index + 2, temp.end());
			int a = stoi(as);
			int b = stoi(bs);
			
			cout << a + b << '\n';
		}
		else if (temp == "P=NP") {
			cout << "skipped\n";
		}
	}
}

