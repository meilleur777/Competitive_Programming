#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    while (getline(cin, s, '\n')) {
        for (auto& c:s) {
            switch (c) {
                case 'i':c='e'; break;
                case 'e':c='i'; break;
                case 'I':c='E'; break;
                case 'E':c='I';
            }
        }
        cout << s << '\n';
    }

    return 0;
}
