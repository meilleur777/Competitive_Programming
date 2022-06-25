#include <bits/stdc++.h>    
using namespace std;

int main() {
    vector<string> words(5);

    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (words[j].size() - 1 < i) continue;
            cout << words[j][i];
        }
        
    }
}

