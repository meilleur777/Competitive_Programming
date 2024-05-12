#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int i=1;
    cout << "The largest square has side length ";
    while (true) {
        if ((i+1)*(i+1)>n) {
            cout << i << ".";
            break;
        }
        i++;
    }

    return 0;
}
