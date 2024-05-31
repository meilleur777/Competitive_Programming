#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();

    int now=0;
    int score=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='g') {
            if (now>0) {
                now--;
                score++;
            }
            else {
                now++;
            }
        }
        else if (s[i]=='p') {
            if (now>0) {
                now--;
            }
            else {
                now++;
                score--;
            }
        }
    }

    cout << score;

    return 0;
}
